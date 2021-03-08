#include "fixed_rate_bond_pricing_request.h"
#include <map>

void FixedRateBondPricingRequest::request(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, const quantra::PriceFixedRateBondRequest *request)
{

    FixedRateBondParser bond_parser = FixedRateBondParser();
    TermStructureParser term_structure_parser = TermStructureParser();

    auto pricing = request->pricing();

    Date as_of_date = DateToQL(pricing->as_of_date()->c_str());
    Settings::instance().evaluationDate() = as_of_date;

    auto curves = pricing->curves();

    std::map<std::string, std::shared_ptr<PricingEngine>> pricing_engines;
    std::map<std::string, std::shared_ptr<RelinkableHandle<YieldTermStructure>>> term_structures;

    for (auto it = curves->begin(); it != curves->end(); it++)
    {

        std::shared_ptr<RelinkableHandle<YieldTermStructure>> discounting_term_structure;
        std::shared_ptr<PricingEngine> bond_engine(new QuantLib::DiscountingBondEngine(*discounting_term_structure));
        std::shared_ptr<YieldTermStructure> term_structure = term_structure_parser.parse(*it);
        discounting_term_structure->linkTo(term_structure);
        pricing_engines.insert(std::make_pair(it->id()->str(), bond_engine));
        term_structures.insert(std::make_pair(it->id()->str(), discounting_term_structure));
    }

    auto bond_pricings = request->bonds();

    PriceFixedRateBondResponseBuilder response_builder(*builder);

    for (auto it = bond_pricings->begin(); it != bond_pricings->end(); it++)
    {

        auto engine = pricing_engines.find(it->discounting_curve()->str());
        auto term_structure = term_structures.find(it->discounting_curve()->str());

        if (engine == pricing_engines.end())
        {
            //handle error
        }
        else
        {
            std::shared_ptr<QuantLib::FixedRateBond> bond = bond_parser.parse(it->fixed_rate_bond());
            bond->setPricingEngine(engine->second);
            response_builder.add_npv(bond->NPV());

            if (pricing->bond_pricing_details())
            {
                auto yield = bond->yield(DayCounterToQL(it->yield()->day_counter()),
                                         CompoundingToQL(it->yield()->compounding()),
                                         FrequencyToQL(it->yield()->frequency()));

                response_builder.add_clean_price(bond->cleanPrice());
                response_builder.add_dirty_price(bond->dirtyPrice());
                response_builder.add_accrued_amount(bond->accruedAmount());
                response_builder.add_yield(yield);
                response_builder.add_accrued_days(BondFunctions::accruedDays(*bond));

                InterestRate interest_rate(yield, DayCounterToQL(it->yield()->day_counter()),
                                           CompoundingToQL(it->yield()->compounding()),
                                           FrequencyToQL(it->yield()->frequency()));

                response_builder.add_modified_duration(BondFunctions::duration(*bond, interest_rate,
                                                                               Duration::Modified, Settings::instance().evaluationDate()));
                response_builder.add_macaulay_duration(BondFunctions::duration(*bond, interest_rate,
                                                                               Duration::Macaulay, Settings::instance().evaluationDate()));
                response_builder.add_macaulay_duration(BondFunctions::convexity(*bond, interest_rate, Settings::instance().evaluationDate()));
                response_builder.add_bps(BondFunctions::bps(*bond, *term_structure->second->currentLink(), Settings::instance().evaluationDate()));
            }

            if (pricing->bond_pricing_flows())
            {
                const Leg &cashflows = bond->cashflows();
                std::vector<flatbuffers::Offset<quantra::FlowsWrapper>> flows_vector;

                for (auto it = cashflows.begin(); it != cashflows.end(); ++it)
                {
                    auto coupon = std::dynamic_pointer_cast<FixedRateCoupon>(*it);
                    if (coupon)
                    {
                        if (!coupon->hasOccurred(Settings::instance().evaluationDate()))
                        {
                            auto accrual_start_date = builder->CreateString(coupon->accrualStartDate());
                            auto accrual_end_date = builder->CreateString(coupon->accrualEndDate());
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
                            auto accrual_start_date = builder->CreateString(coupon->accrualStartDate());
                            auto accrual_end_date = builder->CreateString(coupon->accrualEndDate());
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
                            auto date = builder->CreateString(coupon->date());
                            auto flow_notional_builder = FlowNotionalBuilder(*builder);
                            flow_notional_builder.add_amount(coupon->amount());
                            flow_notional_builder.add_date(date);
                            flow_notional_builder.add_discount(term_structure->second->currentLink()->discount(coupon->date()));
                            flow_notional_builder.add_price(coupon->amount() *
                                                            term_structure->second->currentLink()->discount(coupon->date()));
                            auto flow_past_interest = flow_notional_builder.Finish();

                            auto flows_wrapper_builder = quantra::FlowsWrapperBuilder(*builder);
                            flows_wrapper_builder.add_flow_wrapper_type(quantra::Flow_FlowPastInterest);
                            flows_wrapper_builder.add_flow_wrapper(flow_past_interest.Union());
                            auto flow = flows_wrapper_builder.Finish();
                            flows_vector.push_back(flow);
                        }
                    }
                }
            }
        }
    }