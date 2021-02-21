#include "common_parser.h"

std::shared_ptr<PricingStruct> PricingParser::parse(const quantra::Pricing *p)
{
    PricingStruct pricing_struct = {
        DateToQL(p->as_of_date()->str()),
    };
    return std::make_shared<PricingStruct>(pricing_struct);
}

std::shared_ptr<QuantLib::Schedule> ScheduleParser::parse(const quantra::Schedule *schedule)
{
    return std::make_shared<PricingStruct>(pricing_struct);
}