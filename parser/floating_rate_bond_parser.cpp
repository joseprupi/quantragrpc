#include "floating_rate_bond_parser.h"

std::shared_ptr<QuantLib::FloatingRateBond> FixedRateBondParser::parse(const quantra::FloatingRateBond *bond)
{
    if (bond == NULL)
        QUANTRA_ERROR("Floating Rate Bond not found");

    ScheduleParser schedule_parser = ScheduleParser();
    IndexParser index_parser = IndexParser();

    return std::make_shared<QuantLib::FloatingRateBond>(
        bond->settlement_days(),
        bond->face_amount(),
        *schedule_parser.parse(bond->schedule()),
        index_parser.parse(bond->index()),
        DayCounterToQL(bond->accrual_day_counter()),
        ConventionToQL(bond->payment_convention()),
        bond->fixing_days(),
        std::vector<Real>(1, 1.0),
        std::vector<Spread>(1, bond->spread()),
        std::vector<Rate>(),
        std::vector<Rate>(),
        bond->in_arrears(),
        bond->redemption(),
        DateToQL(bond->issue_date()->str()));
}