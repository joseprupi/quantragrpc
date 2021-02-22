#include "common_parser.h"

std::shared_ptr<PricingStruct> PricingParser::parse(const quantra::Pricing *p)
{
    // PricingStruct pricing_struct = {
    //     DateToQL(p->as_of_date()->str()),
    // };
    return std::make_shared<PricingStruct>(PricingStruct{DateToQL(p->as_of_date()->str())});
}

std::shared_ptr<QuantLib::Schedule> ScheduleParser::parse(const quantra::Schedule *schedule)
{
    return std::make_shared<QuantLib::Schedule>(
        DateToQL(schedule->effective_date()->str()),
        DateToQL(schedule->termination_date()->str()),
        QuantLib::Period(FrequencyToQL(schedule->frequency())),
        CalendarToQL(schedule->calendar()),
        ConventionToQL(schedule->convention()),
        ConventionToQL(schedule->termination_date_convention()),
        DateGenerationToQL(schedule->date_generation_rule()),
        schedule->end_of_mont());
}

std::shared_ptr<YieldStruct> YieldParser::parse(const quantra::Yield *yield)
{
    return std::make_shared<YieldStruct>(
        YieldStruct{
            DayCounterToQL(yield->day_counter()),
            CompoundingToQL(yield->compounding()),
            FrequencyToQL(yield->frequency())});
}