#include "fixed_rate_bond_parser.h"

std::shared_ptr<QuantLib::FixedRateBond> FixedRateBondParser::parse(const quantra::FixedRateBond *bond)
{
    return std::make_shared<QuantLib::FixedRateBond>(
        bond->settlement_days(),
        bond->face_amount(),
        bond->schedule(),
        bond->rate(),
        bond->day_counter(),
        bond->business_day_convention(),
        bond->redemption(),
        bond->issue_date());
}