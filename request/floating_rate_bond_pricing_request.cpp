#include "floating_rate_bond_pricing_request.h"

#include <ql/qldefines.hpp>
#if !defined(BOOST_ALL_NO_LIB) && defined(BOOST_MSVC)
#include <ql/auto_link.hpp>
#endif
#include <ql/instruments/bonds/zerocouponbond.hpp>
#include <ql/instruments/bonds/floatingratebond.hpp>
#include <ql/pricingengines/bond/discountingbondengine.hpp>
#include <ql/cashflows/couponpricer.hpp>
#include <ql/termstructures/yield/piecewiseyieldcurve.hpp>
#include <ql/termstructures/yield/bondhelpers.hpp>
#include <ql/termstructures/volatility/optionlet/constantoptionletvol.hpp>
#include <ql/indexes/ibor/euribor.hpp>
#include <ql/indexes/ibor/usdlibor.hpp>
#include <ql/time/calendars/target.hpp>
#include <ql/time/calendars/unitedstates.hpp>
#include <ql/time/daycounters/actualactual.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/time/daycounters/thirty360.hpp>

#include <iostream>
#include <iomanip>

using namespace QuantLib;

flatbuffers::Offset<quantra::PriceFloatingRateBondResponse> FloatingRateBondPricingRequest::request(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, const quantra::PriceFloatingRateBondRequest *request) const
{

    PricingParser pricing_parser = PricingParser();
    FloatingRateBondParser bond_parser = FloatingRateBondParser();
    TermStructureParser term_structure_parser = TermStructureParser();

    auto pricing = pricing_parser.parse(request->pricing());

    Date as_of_date = DateToQL(pricing->as_of_date);
    Settings::instance().evaluationDate() = as_of_date;

    Date settlement_date = DateToQL(pricing->settlement_date);

    auto curves = pricing->curves;
    auto pricers = pricing->coupon_pricers;

    std::map<std::string, std::shared_ptr<YieldTermStructure>> term_structures;

    for (auto it = curves->begin(); it != curves->end(); it++)
    {
        std::shared_ptr<YieldTermStructure> term_structure = term_structure_parser.parse(*it);
        term_structures.insert(std::make_pair(it->id()->str(), term_structure));
    }

    // std::map<std::string, std::shared_ptr<YieldTermStructure>> term_structures;

    for (auto it = curves->begin(); it != curves->end(); it++)
    {
        std::shared_ptr<YieldTermStructure> term_structure = term_structure_parser.parse(*it);
        term_structures.insert(std::make_pair(it->id()->str(), term_structure));
    }

    auto bond_pricings = request->bonds();

    std::vector<flatbuffers::Offset<quantra::FloatingRateBondResponse>> bonds_vector;

    for (auto it = bond_pricings->begin(); it != bond_pricings->end(); it++)
    {

        auto discounting_term_structure = term_structures.find(it->discounting_curve()->str());
        auto forecasting_term_structure = term_structures.find(it->forecasting_curve()->str());

        if (discounting_term_structure == term_structures.end() || forecasting_term_structure == term_structures.end())
        {
            PriceFloatingRateBondResponseBuilder response_builder(*builder);
            return response_builder.Finish();
        }
        else
        {
            RelinkableHandle<YieldTermStructure> discounting_term_structure_handle;
            discounting_term_structure_handle.linkTo(discounting_term_structure->second);
            std::shared_ptr<PricingEngine> bond_engine(new QuantLib::DiscountingBondEngine(discounting_term_structure_handle));
#pragma region

            /* Test */

            std::cout << std::endl;

            /*********************
             ***  MARKET DATA  ***
             *********************/

            Calendar calendar = TARGET();

            Date settlementDate(18, September, 2008);
            // must be a business day
            settlementDate = calendar.adjust(settlementDate);

            Integer fixingDays = 3;
            Natural settlementDays = 3;

            Date todaysDate = calendar.advance(settlementDate, -fixingDays, Days);
            // nothing to do with Date::todaysDate
            Settings::instance().evaluationDate() = todaysDate;

            std::cout << "Today: " << todaysDate.weekday()
                      << ", " << todaysDate << std::endl;

            std::cout << "Settlement date: " << settlementDate.weekday()
                      << ", " << settlementDate << std::endl;

            // Building of the bonds discounting yield curve

            /*********************
             ***  RATE HELPERS ***
             *********************/

            // RateHelpers are built from the above quotes together with
            // other instrument dependant infos.  Quotes are passed in
            // relinkable handles which could be relinked to some other
            // data source later.

            // Common data

            // ZC rates for the short end
            Rate zc3mQuote = 0.0096;
            Rate zc6mQuote = 0.0145;
            Rate zc1yQuote = 0.0194;

            ext::shared_ptr<Quote> zc3mRate(new SimpleQuote(zc3mQuote));
            ext::shared_ptr<Quote> zc6mRate(new SimpleQuote(zc6mQuote));
            ext::shared_ptr<Quote> zc1yRate(new SimpleQuote(zc1yQuote));

            DayCounter zcBondsDayCounter = Actual365Fixed();

            ext::shared_ptr<RateHelper> zc3m(new DepositRateHelper(
                Handle<Quote>(zc3mRate),
                3 * Months, fixingDays,
                calendar, ModifiedFollowing,
                true, zcBondsDayCounter));
            ext::shared_ptr<RateHelper> zc6m(new DepositRateHelper(
                Handle<Quote>(zc6mRate),
                6 * Months, fixingDays,
                calendar, ModifiedFollowing,
                true, zcBondsDayCounter));
            ext::shared_ptr<RateHelper> zc1y(new DepositRateHelper(
                Handle<Quote>(zc1yRate),
                1 * Years, fixingDays,
                calendar, ModifiedFollowing,
                true, zcBondsDayCounter));

            // setup bonds
            Real redemption = 100.0;

            const Size numberOfBonds = 5;

            Date issueDates[] = {
                Date(15, March, 2005),
                Date(15, June, 2005),
                Date(30, June, 2006),
                Date(15, November, 2002),
                Date(15, May, 1987)};

            Date maturities[] = {
                Date(31, August, 2010),
                Date(31, August, 2011),
                Date(31, August, 2013),
                Date(15, August, 2018),
                Date(15, May, 2038)};

            Real couponRates[] = {
                0.02375,
                0.04625,
                0.03125,
                0.04000,
                0.04500};

            Real marketQuotes[] = {
                100.390625,
                106.21875,
                100.59375,
                101.6875,
                102.140625};

            std::vector<ext::shared_ptr<SimpleQuote>> quote;
            for (double marketQuote : marketQuotes)
            {
                ext::shared_ptr<SimpleQuote> cp(new SimpleQuote(marketQuote));
                quote.push_back(cp);
            }

            RelinkableHandle<Quote> quoteHandle[numberOfBonds];
            for (Size i = 0; i < numberOfBonds; i++)
            {
                quoteHandle[i].linkTo(quote[i]);
            }

            // Definition of the rate helpers
            std::vector<ext::shared_ptr<QuantLib::BondHelper>> bondsHelpers;

            for (Size i = 0; i < numberOfBonds; i++)
            {

                QuantLib::Schedule schedule(issueDates[i], maturities[i], Period(Semiannual), UnitedStates(UnitedStates::GovernmentBond),
                                            Unadjusted, Unadjusted, DateGeneration::Backward, false);

                ext::shared_ptr<FixedRateBondHelper> bondHelper(new FixedRateBondHelper(
                    quoteHandle[i],
                    settlementDays,
                    100.0,
                    schedule,
                    std::vector<Rate>(1, couponRates[i]),
                    ActualActual(ActualActual::Bond),
                    Unadjusted,
                    redemption,
                    issueDates[i]));

                // the above could also be done by creating a
                // FixedRateBond instance and writing:
                //
                // ext::shared_ptr<BondHelper> bondHelper(
                //         new BondHelper(quoteHandle[i], bond));
                //
                // This would also work for bonds that still don't have a
                // specialized helper, such as floating-rate bonds.

                bondsHelpers.push_back(bondHelper);
            }

            /*********************
             **  CURVE BUILDING **
             *********************/

            // Any DayCounter would be fine.
            // ActualActual::ISDA ensures that 30 years is 30.0
            DayCounter termStructureDayCounter =
                ActualActual(ActualActual::ISDA);

            // A depo-bond curve
            std::vector<ext::shared_ptr<RateHelper>> bondInstruments;

            // Adding the ZC bonds to the curve for the short end
            bondInstruments.push_back(zc3m);
            bondInstruments.push_back(zc6m);
            bondInstruments.push_back(zc1y);

            // Adding the Fixed rate bonds to the curve for the long end
            for (Size i = 0; i < numberOfBonds; i++)
            {
                bondInstruments.push_back(bondsHelpers[i]);
            }

            ext::shared_ptr<YieldTermStructure> bondDiscountingTermStructure(
                new PiecewiseYieldCurve<Discount, LogLinear>(
                    settlementDate, bondInstruments,
                    termStructureDayCounter));

            // Building of the Libor forecasting curve
            // deposits
            Rate d1wQuote = 0.043375;
            Rate d1mQuote = 0.031875;
            Rate d3mQuote = 0.0320375;
            Rate d6mQuote = 0.03385;
            Rate d9mQuote = 0.0338125;
            Rate d1yQuote = 0.0335125;
            // swaps
            Rate s2yQuote = 0.0295;
            Rate s3yQuote = 0.0323;
            Rate s5yQuote = 0.0359;
            Rate s10yQuote = 0.0412;
            Rate s15yQuote = 0.0433;

            /********************
             ***    QUOTES    ***
             ********************/

            // SimpleQuote stores a value which can be manually changed;
            // other Quote subclasses could read the value from a database
            // or some kind of data feed.

            // deposits
            ext::shared_ptr<Quote> d1wRate(new SimpleQuote(d1wQuote));
            ext::shared_ptr<Quote> d1mRate(new SimpleQuote(d1mQuote));
            ext::shared_ptr<Quote> d3mRate(new SimpleQuote(d3mQuote));
            ext::shared_ptr<Quote> d6mRate(new SimpleQuote(d6mQuote));
            ext::shared_ptr<Quote> d9mRate(new SimpleQuote(d9mQuote));
            ext::shared_ptr<Quote> d1yRate(new SimpleQuote(d1yQuote));
            // swaps
            ext::shared_ptr<Quote> s2yRate(new SimpleQuote(s2yQuote));
            ext::shared_ptr<Quote> s3yRate(new SimpleQuote(s3yQuote));
            ext::shared_ptr<Quote> s5yRate(new SimpleQuote(s5yQuote));
            ext::shared_ptr<Quote> s10yRate(new SimpleQuote(s10yQuote));
            ext::shared_ptr<Quote> s15yRate(new SimpleQuote(s15yQuote));

            /*********************
             ***  RATE HELPERS ***
             *********************/

            // RateHelpers are built from the above quotes together with
            // other instrument dependant infos.  Quotes are passed in
            // relinkable handles which could be relinked to some other
            // data source later.

            // deposits
            DayCounter depositDayCounter = Actual360();

            ext::shared_ptr<RateHelper> d1w(new DepositRateHelper(
                Handle<Quote>(d1wRate),
                1 * Weeks, fixingDays,
                calendar, ModifiedFollowing,
                true, depositDayCounter));
            ext::shared_ptr<RateHelper> d1m(new DepositRateHelper(
                Handle<Quote>(d1mRate),
                1 * Months, fixingDays,
                calendar, ModifiedFollowing,
                true, depositDayCounter));
            ext::shared_ptr<RateHelper> d3m(new DepositRateHelper(
                Handle<Quote>(d3mRate),
                3 * Months, fixingDays,
                calendar, ModifiedFollowing,
                true, depositDayCounter));
            ext::shared_ptr<RateHelper> d6m(new DepositRateHelper(
                Handle<Quote>(d6mRate),
                6 * Months, fixingDays,
                calendar, ModifiedFollowing,
                true, depositDayCounter));
            ext::shared_ptr<RateHelper> d9m(new DepositRateHelper(
                Handle<Quote>(d9mRate),
                9 * Months, fixingDays,
                calendar, ModifiedFollowing,
                true, depositDayCounter));
            ext::shared_ptr<RateHelper> d1y(new DepositRateHelper(
                Handle<Quote>(d1yRate),
                1 * Years, fixingDays,
                calendar, ModifiedFollowing,
                true, depositDayCounter));

            // setup swaps
            Frequency swFixedLegFrequency = Annual;
            BusinessDayConvention swFixedLegConvention = Unadjusted;
            DayCounter swFixedLegDayCounter = Thirty360(Thirty360::European);
            ext::shared_ptr<IborIndex> swFloatingLegIndex(new Euribor6M);

            const Period forwardStart(1 * Days);

            ext::shared_ptr<RateHelper> s2y(new SwapRateHelper(
                Handle<Quote>(s2yRate), 2 * Years,
                calendar, swFixedLegFrequency,
                swFixedLegConvention, swFixedLegDayCounter,
                swFloatingLegIndex, Handle<Quote>(), forwardStart));
            ext::shared_ptr<RateHelper> s3y(new SwapRateHelper(
                Handle<Quote>(s3yRate), 3 * Years,
                calendar, swFixedLegFrequency,
                swFixedLegConvention, swFixedLegDayCounter,
                swFloatingLegIndex, Handle<Quote>(), forwardStart));
            ext::shared_ptr<RateHelper> s5y(new SwapRateHelper(
                Handle<Quote>(s5yRate), 5 * Years,
                calendar, swFixedLegFrequency,
                swFixedLegConvention, swFixedLegDayCounter,
                swFloatingLegIndex, Handle<Quote>(), forwardStart));
            ext::shared_ptr<RateHelper> s10y(new SwapRateHelper(
                Handle<Quote>(s10yRate), 10 * Years,
                calendar, swFixedLegFrequency,
                swFixedLegConvention, swFixedLegDayCounter,
                swFloatingLegIndex, Handle<Quote>(), forwardStart));
            ext::shared_ptr<RateHelper> s15y(new SwapRateHelper(
                Handle<Quote>(s15yRate), 15 * Years,
                calendar, swFixedLegFrequency,
                swFixedLegConvention, swFixedLegDayCounter,
                swFloatingLegIndex, Handle<Quote>(), forwardStart));

            /*********************
             **  CURVE BUILDING **
             *********************/

            // Any DayCounter would be fine.
            // ActualActual::ISDA ensures that 30 years is 30.0

            // A depo-swap curve
            std::vector<ext::shared_ptr<QuantLib::RateHelper>> depoSwapInstruments;
            depoSwapInstruments.push_back(d1w);
            depoSwapInstruments.push_back(d1m);
            depoSwapInstruments.push_back(d3m);
            depoSwapInstruments.push_back(d6m);
            depoSwapInstruments.push_back(d9m);
            depoSwapInstruments.push_back(d1y);
            depoSwapInstruments.push_back(s2y);
            depoSwapInstruments.push_back(s3y);
            depoSwapInstruments.push_back(s5y);
            depoSwapInstruments.push_back(s10y);
            depoSwapInstruments.push_back(s15y);
            ext::shared_ptr<YieldTermStructure> depoSwapTermStructure(
                new PiecewiseYieldCurve<Discount, LogLinear>(
                    settlementDate, depoSwapInstruments,
                    termStructureDayCounter));

            // Term structures that will be used for pricing:
            // the one used for discounting cash flows
            RelinkableHandle<YieldTermStructure> discountingTermStructure;
            // the one used for forward rate forecasting
            RelinkableHandle<YieldTermStructure> forecastingTermStructure;

            /*********************
             * BONDS TO BE PRICED *
             **********************/

            // Common data
            Real faceAmount = 100;

            // Pricing engine
            ext::shared_ptr<PricingEngine> bondEngine(
                new DiscountingBondEngine(discountingTermStructure));

            // Zero coupon bond
            ZeroCouponBond zeroCouponBond(
                settlementDays,
                UnitedStates(UnitedStates::GovernmentBond),
                faceAmount,
                Date(15, August, 2013),
                Following,
                Real(116.92),
                Date(15, August, 2003));

            zeroCouponBond.setPricingEngine(bond_engine);

            // Fixed 4.5% US Treasury Note
            QuantLib::Schedule fixedBondSchedule(Date(15, May, 2007),
                                                 Date(15, May, 2017), Period(Semiannual),
                                                 UnitedStates(UnitedStates::GovernmentBond),
                                                 Unadjusted, Unadjusted, DateGeneration::Backward, false);

            QuantLib::FixedRateBond fixedRateBond(
                settlementDays,
                faceAmount,
                fixedBondSchedule,
                std::vector<Rate>(1, 0.045),
                ActualActual(ActualActual::Bond),
                ModifiedFollowing,
                100.0, Date(15, May, 2007));

            fixedRateBond.setPricingEngine(bondEngine);

            // Floating rate bond (3M USD Libor + 0.1%)
            // Should and will be priced on another curve later...

            RelinkableHandle<YieldTermStructure> liborTermStructure;
            const ext::shared_ptr<IborIndex> libor3m(
                new USDLibor(Period(3, Months), liborTermStructure));
            libor3m->addFixing(Date(17, July, 2008), 0.0278625);

            QuantLib::Schedule floatingBondSchedule(Date(21, October, 2005),
                                                    Date(21, October, 2010), Period(Quarterly),
                                                    UnitedStates(UnitedStates::NYSE),
                                                    Unadjusted, Unadjusted, DateGeneration::Backward, true);

            QuantLib::FloatingRateBond floatingRateBond(
                settlementDays,
                faceAmount,
                floatingBondSchedule,
                libor3m,
                Actual360(),
                ModifiedFollowing,
                Natural(2),
                // Gearings
                std::vector<Real>(1, 1.0),
                // Spreads
                std::vector<Rate>(1, 0.001),
                // Caps
                std::vector<Rate>(),
                // Floors
                std::vector<Rate>(),
                // Fixing in arrears
                true,
                Real(100.0),
                Date(21, October, 2005));

            floatingRateBond.setPricingEngine(bond_engine);

            // Coupon pricers
            ext::shared_ptr<QuantLib::IborCouponPricer> pricer(new QuantLib::BlackIborCouponPricer);

            // optionLet volatilities
            QuantLib::Volatility volatility = 0.0;
            Handle<QuantLib::OptionletVolatilityStructure> vol;
            vol = Handle<QuantLib::OptionletVolatilityStructure>(ext::shared_ptr<QuantLib::OptionletVolatilityStructure>(new QuantLib::ConstantOptionletVolatility(
                settlementDays,
                calendar,
                ModifiedFollowing,
                volatility,
                Actual365Fixed())));

            pricer->setCapletVolatility(vol);
            setCouponPricer(floatingRateBond.cashflows(), pricer);
            // std::shared_ptr<QuantLib::FloatingRateCouponPricer> pricer(
            //     new QuantLib::BlackIborCouponPricer);
            setCouponPricer(floatingRateBond.cashflows(), pricer);

            /* Test */
#pragma endregion
            std::shared_ptr<QuantLib::FloatingRateBond> bond = bond_parser.parse(it->floating_rate_bond());
            bond_parser.index_parser.link_term_structure(forecasting_term_structure->second);
            std::vector<flatbuffers::Offset<quantra::FlowsWrapper>> flows_vector;
            bond->setPricingEngine(bondEngine);

            discountingTermStructure.linkTo(discounting_term_structure->second);
            liborTermStructure.linkTo(forecasting_term_structure->second);

            auto npv = floatingRateBond.NPV();

            if (pricing->bond_pricing_flows)
            {
                const Leg &cashflows = bond->cashflows();

                for (auto it = cashflows.begin(); it != cashflows.end(); ++it)
                {
                    auto coupon = std::dynamic_pointer_cast<FloatingRateCoupon>(*it);
                    if (coupon)
                    {
                        if (!coupon->hasOccurred(Settings::instance().evaluationDate()))
                        {
                            std::ostringstream os_start_date;
                            os_start_date << QuantLib::io::iso_date(coupon->accrualStartDate());
                            auto accrual_start_date = builder->CreateString(os_start_date.str());

                            std::ostringstream os_end_date;
                            os_end_date << QuantLib::io::iso_date(coupon->accrualEndDate());
                            auto accrual_end_date = builder->CreateString(os_end_date.str());

                            auto flow_interest_builder = FlowInterestBuilder(*builder);
                            flow_interest_builder.add_amount(coupon->amount());
                            flow_interest_builder.add_fixing_date(coupon->indexFixing());
                            flow_interest_builder.add_accrual_start_date(accrual_start_date);
                            flow_interest_builder.add_accrual_end_date(accrual_end_date);
                            flow_interest_builder.add_rate(coupon->rate());
                            flow_interest_builder.add_discount(discounting_term_structure->second->discount(coupon->date()));
                            flow_interest_builder.add_price(coupon->amount() *
                                                            discounting_term_structure->second->discount(coupon->date()));
                            auto flow_interest = flow_interest_builder.Finish();

                            auto flows_wrapper_builder = quantra::FlowsWrapperBuilder(*builder);
                            flows_wrapper_builder.add_flow_type(quantra::Flow_FlowInterest);
                            flows_wrapper_builder.add_flow(flow_interest.Union());
                            auto flow = flows_wrapper_builder.Finish();
                            flows_vector.push_back(flow);
                        }
                        else
                        {
                            std::ostringstream os_start_date;
                            os_start_date << QuantLib::io::iso_date(coupon->accrualStartDate());
                            auto accrual_start_date = builder->CreateString(os_start_date.str());

                            std::ostringstream os_end_date;
                            os_end_date << QuantLib::io::iso_date(coupon->accrualEndDate());
                            auto accrual_end_date = builder->CreateString(os_end_date.str());

                            auto flow_past_interest_builder = FlowPastInterestBuilder(*builder);
                            flow_past_interest_builder.add_amount(coupon->amount());
                            flow_past_interest_builder.add_fixing_date(coupon->indexFixing());
                            flow_past_interest_builder.add_accrual_start_date(accrual_start_date);
                            flow_past_interest_builder.add_accrual_end_date(accrual_end_date);
                            flow_past_interest_builder.add_rate(coupon->rate());
                            auto flow_past_interest = flow_past_interest_builder.Finish();

                            auto flows_wrapper_builder = quantra::FlowsWrapperBuilder(*builder);
                            flows_wrapper_builder.add_flow_type(quantra::Flow_FlowPastInterest);
                            flows_wrapper_builder.add_flow(flow_past_interest.Union());
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
                            flow_notional_builder.add_discount(discounting_term_structure->second->discount(coupon->date()));
                            flow_notional_builder.add_price(coupon->amount() *
                                                            discounting_term_structure->second->discount(coupon->date()));
                            auto flow_past_interest = flow_notional_builder.Finish();

                            auto flows_wrapper_builder = quantra::FlowsWrapperBuilder(*builder);
                            flows_wrapper_builder.add_flow_type(quantra::Flow_FlowNotional);
                            flows_wrapper_builder.add_flow(flow_past_interest.Union());
                            auto flow = flows_wrapper_builder.Finish();
                            flows_vector.push_back(flow);
                        }
                    }
                }
            }

            auto flows = builder->CreateVector(flows_vector);

            FloatingRateBondResponseBuilder response_builder(*builder);

            response_builder.add_flows(flows);

            response_builder.add_npv(bond->NPV());

            if (pricing->bond_pricing_details)
            {
                YieldParser yield_parser = YieldParser();
                auto yield_struct = yield_parser.parse(it->yield());

                auto yield = bond->yield(yield_struct->day_counter, yield_struct->compounding,
                                         yield_struct->frequency);

                response_builder.add_clean_price(bond->cleanPrice());
                response_builder.add_dirty_price(bond->dirtyPrice());
                response_builder.add_accrued_amount(bond->accruedAmount());
                response_builder.add_yield(yield);
                response_builder.add_accrued_days(BondFunctions::accruedDays(*bond));

                InterestRate interest_rate(yield, DayCounterToQL(it->yield()->day_counter()),
                                           CompoundingToQL(it->yield()->compounding()),
                                           FrequencyToQL(it->yield()->frequency()));

                response_builder.add_modified_duration(BondFunctions::duration(*bond, interest_rate,
                                                                               Duration::Modified, settlement_date));
                response_builder.add_macaulay_duration(BondFunctions::duration(*bond, interest_rate,
                                                                               Duration::Macaulay, settlement_date));
                response_builder.add_convexity(BondFunctions::convexity(*bond, interest_rate, settlement_date));
                response_builder.add_bps(BondFunctions::bps(*bond, *discounting_term_structure->second, settlement_date));
            }

            auto bond_response = response_builder.Finish();
            bonds_vector.push_back(bond_response);
        }
    }
    auto bonds = builder->CreateVector(bonds_vector);
    PriceFloatingRateBondResponseBuilder response_builder(*builder);
    response_builder.add_bonds(bonds);

    return response_builder.Finish();
}