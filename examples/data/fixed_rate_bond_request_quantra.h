#include "quantra_structs.h"

using namespace structs;

PriceFixedRateBondRequest request()
{
    std::vector<Point> points;

    DepositHelper deposit_zc3m = {
        .rate = 0.0096,
        .tenor_time_unit = TimeUnit_Months,
        .tenor_number = 3,
        .fixing_days = 3,
        .calendar = Calendar_TARGET,
        .business_day_convention = BusinessDayConvention_ModifiedFollowing,
        .day_counter = DayCounter_Actual365Fixed};

    Point deposit_zc3m_point = {
        .point_type = Deposit,
        .deposit_helper = deposit_zc3m};

    points.push_back(deposit_zc3m_point);

    DepositHelper deposit_zc6m = {
        .rate = 0.0145,
        .tenor_time_unit = TimeUnit_Months,
        .tenor_number = 6,
        .fixing_days = 3,
        .calendar = Calendar_TARGET,
        .business_day_convention = BusinessDayConvention_ModifiedFollowing,
        .day_counter = DayCounter_Actual365Fixed};

    Point deposit_zc6m_point = {
        .point_type = Deposit,
        .deposit_helper = deposit_zc6m};

    points.push_back(deposit_zc6m_point);

    DepositHelper deposit_zc1y = {
        .rate = 0.0194,
        .tenor_time_unit = TimeUnit_Years,
        .tenor_number = 1,
        .fixing_days = 3,
        .calendar = Calendar_TARGET,
        .business_day_convention = BusinessDayConvention_ModifiedFollowing,
        .day_counter = DayCounter_Actual365Fixed};

    Point deposit_zc1y_point = {
        .point_type = Deposit,
        .deposit_helper = deposit_zc1y};

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

        Schedule schedule = {
            .calendar = Calendar_UnitedStatesGovernmentBond,
            .effective_date = *issue_dates[i],
            .termination_date = *maturities[i],
            .frequency = Frequency_Semiannual,
            .convention = BusinessDayConvention_Unadjusted,
            .termination_date_convention = BusinessDayConvention_Unadjusted,
            .date_generation_rule = DateGenerationRule_Backward,
            .end_of_mont = false};

        BondHelper bond = {
            .rate = 0.0096,
            .settlement_days = 3,
            .face_amount = 100.0,
            .schedule = schedule,
            .coupon_rate = coupon_rates[i],
            .day_counter = DayCounter_ActualActualBond,
            .business_day_convention = BusinessDayConvention_Unadjusted,
            .redemption = 100.0,
            .issue_date = *issue_dates[i]};

        Point bond_point = {
            .point_type = Bond,
            .bond_helper = bond};

        points.push_back(bond_point);
    }

    TermStructure term_structure = {
        .id = "depos",
        .day_counter = DayCounter_ActualActualISDA,
        .interpolator = Interpolator_LogLinear,
        .bootstrap_trait = BootstrapTrait_Discount,
        .as_of_date = "2008/09/18",
        .points = points};

    // Fixed 4.5% US Treasury Note
    Schedule schedule = {
        .calendar = Calendar_UnitedStatesGovernmentBond,
        .effective_date = "2007/05/15",
        .termination_date = "2017/05/15",
        .frequency = Frequency_Semiannual,
        .convention = BusinessDayConvention_Unadjusted,
        .termination_date_convention = BusinessDayConvention_Unadjusted,
        .date_generation_rule = DateGenerationRule_Backward,
        .end_of_mont = false};

    FixedRateBond bond = {
        .settlement_days = 3,
        .face_amount = 100.0,
        .rate = 0.045,
        .accrual_day_counter = DayCounter_ActualActualBond,
        .payment_convention = BusinessDayConvention_ModifiedFollowing,
        .redemption = 100.0,
        .issue_date = "2007/05/15",
        .schedule = schedule};

    PriceFixedRateBond price_fixed_rate_bond;
    price_fixed_rate_bond.fixed_rate_bond = bond;
    strcpy(price_fixed_rate_bond.discounting_curve, "depos");

    std::vector<PriceFixedRateBond> bonds;
    bonds.push_back(price_fixed_rate_bond);

    std::vector<TermStructure> term_structures;

    term_structures.push_back(term_structure);

    Pricing pricing = {
        .as_of_date = "2008/09/16",
        .curves = term_structures};

    PriceFixedRateBondRequest request = {
        .pricing = pricing,
        .bonds = bonds};

    return request;
}
