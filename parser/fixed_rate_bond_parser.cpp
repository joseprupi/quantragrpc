#include "fixed_rate_bond_parser.h"

std::shared_ptr<QuantLib::FixedRateBond> FixedRateBondParser::parse(const quantra::FixedRateBond *bond)
{

    ScheduleParser schedule_parser = ScheduleParser();

    /*return std::make_shared<QuantLib::FixedRateBond>(
        bond->settlement_days(),
        bond->face_amount(),
        schedule_parser.parse(bond->schedule()),
        std::vector<Rate>(1, bond->rate()),
        DayCounterToQL(bond->day_counter()),
        ConventionToQL(bond->business_day_convention()),
        bond->redemption(),
        DateToQL(bond->issue_date()->str()));*/

    QuantLib::Schedule fixedBondSchedule(Date(15, May, 2007),
                                         Date(15, May, 2017), Period(Semiannual),
                                         UnitedStates(UnitedStates::GovernmentBond),
                                         Unadjusted, Unadjusted, DateGeneration::Backward, false);
    int sett = bond->settlement_days();
    return std::make_shared<QuantLib::FixedRateBond>(
        bond->settlement_days(),
        bond->face_amount(),
        *schedule_parser.parse(bond->schedule()),
        std::vector<Rate>(1, bond->rate()),
        DayCounterToQL(bond->day_counter()),
        ConventionToQL(bond->business_day_convention()),
        bond->redemption(),
        DateToQL(bond->issue_date()->str()));
}