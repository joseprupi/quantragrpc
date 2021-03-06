#include "quantra_structs.h"

using namespace structs;

PriceFixedRateBondRequest request()
{
    std::vector<Point> points;

    DepositHelper deposit_zc3m;
    deposit_zc3m.rate = 0.0096;
    deposit_zc3m.tenor_time_unit = TimeUnit_Months;
    deposit_zc3m.tenor_number = 3;
    deposit_zc3m.fixing_days = 3;
    deposit_zc3m.calendar = Calendar_TARGET;
    deposit_zc3m.business_day_convention = BusinessDayConvention_ModifiedFollowing;
    deposit_zc3m.day_counter = DayCounter_Actual365Fixed;

    Point deposit_zc3m_point;
    deposit_zc3m_point.point_type = Deposit;
    deposit_zc3m_point.deposit_helper = deposit_zc3m;

    points.push_back(deposit_zc3m_point);

    DepositHelper deposit_zc6m;
    deposit_zc6m.rate = 0.0145;
    deposit_zc6m.tenor_time_unit = TimeUnit_Months;
    deposit_zc6m.tenor_number = 6;
    deposit_zc6m.fixing_days = 3;
    deposit_zc6m.calendar = Calendar_TARGET;
    deposit_zc6m.business_day_convention = BusinessDayConvention_ModifiedFollowing;
    deposit_zc6m.day_counter = DayCounter_Actual365Fixed;

    Point deposit_zc6m_point;
    deposit_zc6m_point.point_type = Deposit;
    deposit_zc6m_point.deposit_helper = deposit_zc6m;

    points.push_back(deposit_zc6m_point);

    DepositHelper deposit_zc1y;
    deposit_zc1y.rate = 0.0194;
    deposit_zc1y.tenor_time_unit = TimeUnit_Years;
    deposit_zc1y.tenor_number = 1;
    deposit_zc1y.fixing_days = 3;
    deposit_zc1y.calendar = Calendar_TARGET;
    deposit_zc1y.business_day_convention = BusinessDayConvention_ModifiedFollowing;
    deposit_zc1y.day_counter = DayCounter_Actual365Fixed;

    Point deposit_zc1y_point;
    deposit_zc1y_point.point_type = Deposit;
    deposit_zc1y_point.deposit_helper = deposit_zc1y;

    points.push_back(deposit_zc1y_point);

    const char *issue_dates[] = {
        "2005/03/15",
        "2005/06/15",
        "2006/06/30",
        "2002/11/15",
        "1987/05/15"};

    const char *maturities[] = {
        "2010/08/31",
        "2011/08/31",
        "2013/08/31",
        "2018/08/15",
        "2038/05/15"};

    float coupon_rates[] = {
        0.02375,
        0.04625,
        0.03125,
        0.04000,
        0.04500};

    float market_quotes[] = {
        100.390625,
        106.21875,
        100.59375,
        101.6875,
        102.140625};

    int number_of_bonds = 5;

    for (int i = 0; i < number_of_bonds; i++)
    {

        Schedule schedule;
        schedule.calendar = Calendar_UnitedStatesGovernmentBond;
        strcpy(schedule.effective_date, issue_dates[i]);
        strcpy(schedule.termination_date, maturities[i]);
        schedule.frequency = Frequency_Semiannual;
        schedule.convention = BusinessDayConvention_Unadjusted;
        schedule.termination_date_convention = BusinessDayConvention_Unadjusted;
        schedule.date_generation_rule = DateGenerationRule_Backward;
        schedule.end_of_mont = false;

        BondHelper bond;
        bond.rate = 0.0096;
        bond.settlement_days = 3;
        bond.face_amount = 100.0;
        bond.schedule = schedule;
        bond.coupon_rate = coupon_rates[i];
        bond.day_counter = DayCounter_ActualActualBond;
        bond.business_day_convention = BusinessDayConvention_Unadjusted;
        bond.redemption = 100.0;
        strcpy(bond.issue_date, issue_dates[i]);

        Point bond_point;
        bond_point.point_type = Bond;
        bond_point.bond_helper = bond;

        points.push_back(bond_point);
    };

    TermStructure term_structure;
    strcpy(term_structure.id, "depos");
    term_structure.day_counter = DayCounter_ActualActualISDA;
    term_structure.interpolator = Interpolator_LogLinear;
    term_structure.bootstrap_trait = BootstrapTrait_Discount;
    strcpy(term_structure.as_of_date, "2008/09/18");
    term_structure.points = points;

    Schedule schedule;
    schedule.calendar = Calendar_UnitedStatesGovernmentBond;
    strcpy(schedule.effective_date, "2007/05/15");
    strcpy(schedule.termination_date, "2017/05/15");
    schedule.frequency = Frequency_Semiannual;
    schedule.convention = BusinessDayConvention_Unadjusted;
    schedule.termination_date_convention = BusinessDayConvention_Unadjusted;
    schedule.date_generation_rule = DateGenerationRule_Backward;
    schedule.end_of_mont = false;

    FixedRateBond bond;
    bond.settlement_days = 3;
    bond.face_amount = 100.0;
    bond.rate = 0.045;
    bond.accrual_day_counter = DayCounter_ActualActualBond;
    bond.payment_convention = BusinessDayConvention_ModifiedFollowing;
    bond.redemption = 100.0;
    strcpy(bond.issue_date, "2007/05/15");
    bond.schedule = schedule;

    PriceFixedRateBond price_fixed_rate_bond;
    price_fixed_rate_bond.fixed_rate_bond = bond;
    strcpy(price_fixed_rate_bond.discounting_curve, "depos");

    std::vector<PriceFixedRateBond> bonds;
    bonds.push_back(price_fixed_rate_bond);

    std::vector<TermStructure> term_structures;

    term_structures.push_back(term_structure);

    Pricing pricing;
    strcpy(pricing.as_of_date, "2008/09/16");
    pricing.curves = term_structures;

    PriceFixedRateBondRequest request;
    request.pricing = pricing;
    request.bonds = bonds;

    return request;
}
