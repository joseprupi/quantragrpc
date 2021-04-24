#include "fixed_rate_bond_pricing_request.h"

flatbuffers::Offset<quantra::PriceFixedRateBondResponse> FixedRateBondPricingRequest::request(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, const quantra::PriceFixedRateBondRequest *request) const
{
    //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    PricingParser pricing_parser = PricingParser();
    FixedRateBondParser bond_parser = FixedRateBondParser();
    TermStructureParser term_structure_parser = TermStructureParser();

    auto pricing = pricing_parser.parse(request->pricing());

    Date as_of_date = DateToQL(pricing->as_of_date);
    Settings::instance().evaluationDate() = as_of_date;

    auto curves = pricing->curves;

    std::map<std::string, std::shared_ptr<PricingEngine>> pricing_engines;
    std::map<std::string, std::shared_ptr<RelinkableHandle<YieldTermStructure>>> term_structures;

    for (auto it = curves->begin(); it != curves->end(); it++)
    {

        auto discounting_term_structure = std::make_shared<RelinkableHandle<YieldTermStructure>>();
        std::shared_ptr<PricingEngine> bond_engine(new QuantLib::DiscountingBondEngine(*discounting_term_structure));
        std::shared_ptr<YieldTermStructure> term_structure = term_structure_parser.parse(*it);
        discounting_term_structure->linkTo(term_structure);
        pricing_engines.insert(std::make_pair(it->id()->str(), bond_engine));
        term_structures.insert(std::make_pair(it->id()->str(), discounting_term_structure));
    }

    auto bond_pricings = request->bonds();

    std::vector<flatbuffers::Offset<quantra::FixedRateBondResponse>> bonds_vector;

    for (auto it = bond_pricings->begin(); it != bond_pricings->end(); it++)
    {

        auto engine = pricing_engines.find(it->discounting_curve()->str());
        auto term_structure = term_structures.find(it->discounting_curve()->str());

        if (engine == pricing_engines.end())
        {
            PriceFixedRateBondResponseBuilder response_builder(*builder);
            return response_builder.Finish();
        }
        else
        {
            std::shared_ptr<QuantLib::FixedRateBond> bond = bond_parser.parse(it->fixed_rate_bond());
            std::vector<flatbuffers::Offset<quantra::FlowsWrapper>> flows_vector;
            bond->setPricingEngine(engine->second);

            if (pricing->bond_pricing_flows)
            {
                const Leg &cashflows = bond->cashflows();

                for (auto it = cashflows.begin(); it != cashflows.end(); ++it)
                {
                    auto coupon = std::dynamic_pointer_cast<FixedRateCoupon>(*it);
                    if (coupon)
                    {
                        if (!coupon->hasOccurred(Settings::instance().evaluationDate()))
                        {
                            std::ostringstream os;

                            os << QuantLib::io::iso_date(coupon->accrualStartDate());
                            auto accrual_start_date = builder->CreateString(os.str());
                            os << QuantLib::io::iso_date(coupon->accrualEndDate());
                            auto accrual_end_date = builder->CreateString(os.str());
                            auto flow_interest_builder = FlowInterestBuilder(*builder);
                            flow_interest_builder.add_amount(coupon->amount());
                            flow_interest_builder.add_accrual_start_date(accrual_start_date);
                            flow_interest_builder.add_accrual_end_date(accrual_end_date);
                            flow_interest_builder.add_rate(coupon->rate());
                            flow_interest_builder.add_discount(term_structure->second->currentLink()->discount(coupon->date()));
                            flow_interest_builder.add_price(coupon->amount() *
                                                            term_structure->second->currentLink()->discount(coupon->date()));
                            auto flow_interest = flow_interest_builder.Finish();

                            auto flows_wrapper_builder = quantra::FlowsWrapperBuilder(*builder);
                            flows_wrapper_builder.add_flow_wrapper_type(quantra::Flow_FlowInterest);
                            flows_wrapper_builder.add_flow_wrapper(flow_interest.Union());
                            auto flow = flows_wrapper_builder.Finish();
                            flows_vector.push_back(flow);
                        }
                        else
                        {
                            std::ostringstream os;

                            os << QuantLib::io::iso_date(coupon->accrualStartDate());
                            auto accrual_start_date = builder->CreateString(os.str());
                            os << QuantLib::io::iso_date(coupon->accrualEndDate());
                            auto accrual_end_date = builder->CreateString(os.str());
                            auto flow_past_interest_builder = FlowInterestBuilder(*builder);
                            flow_past_interest_builder.add_amount(coupon->amount());
                            flow_past_interest_builder.add_accrual_start_date(accrual_start_date);
                            flow_past_interest_builder.add_accrual_end_date(accrual_end_date);
                            flow_past_interest_builder.add_rate(coupon->rate());
                            auto flow_past_interest = flow_past_interest_builder.Finish();

                            auto flows_wrapper_builder = quantra::FlowsWrapperBuilder(*builder);
                            flows_wrapper_builder.add_flow_wrapper_type(quantra::Flow_FlowPastInterest);
                            flows_wrapper_builder.add_flow_wrapper(flow_past_interest.Union());
                            auto flow = flows_wrapper_builder.Finish();
                            flows_vector.push_back(flow);
                        }
                    }
                    else
                    {
                        auto coupon = std::dynamic_pointer_cast<CashFlow>(*it);

                        if (!coupon->hasOccurred(Settings::instance().evaluationDate()))
                        {
                            std::ostringstream os;

                            os << QuantLib::io::iso_date(coupon->date());
                            auto date = builder->CreateString(os.str());

                            auto flow_notional_builder = FlowNotionalBuilder(*builder);
                            flow_notional_builder.add_amount(coupon->amount());
                            flow_notional_builder.add_date(date);
                            flow_notional_builder.add_discount(term_structure->second->currentLink()->discount(coupon->date()));
                            flow_notional_builder.add_price(coupon->amount() *
                                                            term_structure->second->currentLink()->discount(coupon->date()));
                            auto flow_past_interest = flow_notional_builder.Finish();

                            auto flows_wrapper_builder = quantra::FlowsWrapperBuilder(*builder);
                            flows_wrapper_builder.add_flow_wrapper_type(quantra::Flow_FlowNotional);
                            flows_wrapper_builder.add_flow_wrapper(flow_past_interest.Union());
                            auto flow = flows_wrapper_builder.Finish();
                            flows_vector.push_back(flow);
                        }
                    }
                }
            }

            auto flows = builder->CreateVector(flows_vector);

            FixedRateBondResponseBuilder response_builder(*builder);

            response_builder.add_flows(flows);

            response_builder.add_npv(bond->NPV());

            if (pricing->bond_pricing_details)
            {
                //YieldParser yield_parser = YieldParser();
                //auto yield_struct = yield_parser.parse(it->yield());

                auto yield = bond->yield(pricing->yield_day_counter, pricing->yield_compounding,
                                         pricing->yield_frequency);

                response_builder.add_clean_price(bond->cleanPrice());
                response_builder.add_dirty_price(bond->dirtyPrice());
                response_builder.add_accrued_amount(bond->accruedAmount());
                response_builder.add_yield_value(yield);
                response_builder.add_accrued_days(BondFunctions::accruedDays(*bond));

                InterestRate interest_rate(yield, pricing->yield_day_counter,
                                           pricing->yield_compounding,
                                           pricing->yield_frequency);

                response_builder.add_modified_duration(BondFunctions::duration(*bond, interest_rate,
                                                                               Duration::Modified, Settings::instance().evaluationDate()));
                response_builder.add_macaulay_duration(BondFunctions::duration(*bond, interest_rate,
                                                                               Duration::Macaulay, Settings::instance().evaluationDate()));
                response_builder.add_convexity(BondFunctions::convexity(*bond, interest_rate, Settings::instance().evaluationDate()));
                response_builder.add_bps(BondFunctions::bps(*bond, *term_structure->second->currentLink(), Settings::instance().evaluationDate()));
            }

            auto bond_response = response_builder.Finish();
            bonds_vector.push_back(bond_response);
        }
    }
    auto bonds = builder->CreateVector(bonds_vector);
    PriceFixedRateBondResponseBuilder response_builder(*builder);
    response_builder.add_bonds(bonds);

    //std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //std::cout << "Quantra Server Time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    return response_builder.Finish();
}