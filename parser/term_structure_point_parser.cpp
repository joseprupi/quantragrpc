#include "term_structure_point_parser.h"

std::shared_ptr<RateHelper> TermStructurePointParser::parse(quantra::Point point_type, void *data)
{

    std::shared_ptr<RateHelper> rate_helper;

    if (point_type == quantra::Point_Deposit)
    {
        auto point = static_cast<const Deposit *>(data);

        std::shared_ptr<Quote> quote(new SimpleQuote(point->rate()));

        rate_helper = std::make_shared<RateHelper>(
            new DepositRateHelper(
                Handle<Quote>(quote),
                point->tenor_number() * TimeUnitToQL(point->tenor_time_unit()),
                point->fixing_days(),
                CalendarToQL(point->calendar()),
                ConventionToQL(point->business_day_convention()),
                true,
                DayCounterToQL(point->day_counter())));
    }
    else if (point_type == Point_FRA)
    {
        auto point = static_cast<const FRA *>(data);

        ext::shared_ptr<Quote> quote(new SimpleQuote(point->rate()));

        rate_helper = std::make_shared<RateHelper>(
            new FraRateHelper(
                Handle<Quote>(quote),
                point->months_to_start(),
                point->months_to_end(),
                point->fixing_days(),
                CalendarToQL(point->calendar()),
                ConventionToQL(point->business_day_convention()),
                true,
                DayCounterToQL(point->day_counter())));
    }
    else if (point_type == Point_Future)
    {
        auto point = static_cast<const Future *>(data);

        ext::shared_ptr<Quote> quote(new SimpleQuote(point->rate()));

        rate_helper = std::make_shared<RateHelper>(
            new FuturesRateHelper(
                Handle<Quote>(quote),
                DateToQL(point->future_start_date()->str()),
                point->future_months(),
                CalendarToQL(point->calendar()),
                ConventionToQL(point->business_day_convention()),
                true,
                DayCounterToQL(point->day_counter())));
    }
    else if (point_type == Point_Swap)
    {
        auto point = static_cast<const quantra::Swap *>(data);

        ext::shared_ptr<Quote> quote(new SimpleQuote(point->rate()));
        ext::shared_ptr<Quote> spread(new SimpleQuote(point->spread()));

        rate_helper = std::make_shared<RateHelper>(
            new SwapRateHelper(
                Handle<Quote>(quote),
                point->tenor_number() * TimeUnitToQL(point->tenor_time_unit()),
                CalendarToQL(point->calendar()),
                FrequencyToQL(point->sw_fixed_leg_frequency()),
                ConventionToQL(point->sw_fixed_leg_convention()),
                DayCounterToQL(point->sw_fixed_leg_day_counter()),
                IborToQL(point->sw_floating_leg_index()),
                Handle<Quote>(spread),
                point->fwd_start_days() * QuantLib::Days));
    }

    return rate_helper;
}