#include "term_structure_point_parser.h"

std::shared_ptr<RateHelper> TermStructurePointParser::parse(uint8_t point_type, const void *data)
{

    if (point_type == quantra::Point_Deposit)
    {
        auto point = static_cast<const Deposit *>(data);

        return std::make_shared<DepositRateHelper>(
            point->rate(),
            point->tenor_number() * TimeUnitToQL(point->tenor_time_unit()),
            point->fixing_days(),
            CalendarToQL(point->calendar()),
            ConventionToQL(point->business_day_convention()),
            true,
            DayCounterToQL(point->day_counter()));
    }
    else if (point_type == Point_FRA)
    {
        auto point = static_cast<const FRA *>(data);

        return std::make_shared<FraRateHelper>(
            point->rate(),
            point->months_to_start(),
            point->months_to_end(),
            point->fixing_days(),
            CalendarToQL(point->calendar()),
            ConventionToQL(point->business_day_convention()),
            true,
            DayCounterToQL(point->day_counter()));
    }
    else if (point_type == Point_Future)
    {
        auto point = static_cast<const Future *>(data);

        return std::make_shared<FuturesRateHelper>(
            point->rate(),
            DateToQL(point->future_start_date()->str()),
            point->future_months(),
            CalendarToQL(point->calendar()),
            ConventionToQL(point->business_day_convention()),
            true,
            DayCounterToQL(point->day_counter()));
    }
    else if (point_type == Point_Swap)
    {
        auto point = static_cast<const quantra::Swap *>(data);

        return std::make_shared<SwapRateHelper>(
            point->rate(),
            point->tenor_number() * TimeUnitToQL(point->tenor_time_unit()),
            CalendarToQL(point->calendar()),
            FrequencyToQL(point->sw_fixed_leg_frequency()),
            ConventionToQL(point->sw_fixed_leg_convention()),
            DayCounterToQL(point->sw_fixed_leg_day_counter()),
            IborToQL(point->sw_floating_leg_index()));
    }

    return nullptr;
}