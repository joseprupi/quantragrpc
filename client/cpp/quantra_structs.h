#include "enums_generated.h"

using namespace quantra::enums;

struct Yield;
struct Pricing;
struct Schedule;
struct Fixing;
struct Index;
struct DepositHelper;
struct FRAHelper;
struct FutureHelper;
struct SwapHelper;
struct BondHelper;
union Point;
struct TermStructure;
struct FixedRateBond;
struct FloatingRateBond;
struct PriceFixedRateBond;
struct PriceFixedRateBondRequest;

struct Yield
{
    DayCounter day_counter;
    Compounding compounding;
    Frequency frequency;
};

struct Pricing
{
    std::string as_of_date;
    std::vector<TermStructure> curves;
};

struct Schedule
{
    Calendar calendar;
    std::string effective_date;
    std::string termination_date;
    Frequency frequency;
    BusinessDayConvention convention;
    BusinessDayConvention termination_date_convention;
    DateGenerationRule date_generation_rule;
    bool end_of_mont;
};

struct Fixing
{
    std::string date;
    float rate;
};

struct Index
{
    int period_number;
    TimeUnit period_time_unit;
    int settlement_days;
    Calendar calendar;
    BusinessDayConvention business_day_convention;
    bool end_of_month;
    DayCounter day_counter;
    std::vector<Fixing> fixings;
};

struct DepositHelper
{
    float rate;
    TimeUnit tenor_time_unit;
    int tenor_numbe;
    int fixing_days;
    Calendar calendar;
    BusinessDayConvention business_day_convention;
    DayCounter day_counter;
};

struct FRAHelper
{
    float rate;
    int months_to_start;
    int months_to_end;
    int fixing_days;
    Calendar calendar;
    BusinessDayConvention business_day_convention;
    DayCounter day_counter;
};

struct FutureHelper
{
    float rate;
    std::string future_start_date;
    int future_months;
    Calendar calendar;
    BusinessDayConvention business_day_convention;
    DayCounter day_counter;
};

struct SwapHelper
{
    float rate;
    TimeUnit tenor_time_unit;
    int tenor_number;
    Calendar calendar;
    Frequency sw_fixed_leg_frequency;
    BusinessDayConvention sw_fixed_leg_convention;
    DayCounter sw_fixed_leg_day_counter;
    Ibor sw_floating_leg_index;
    float spread;
    int fwd_start_days;
};

struct BondHelper
{
    float rate;
    int settlement_days;
    float face_amount;
    Schedule schedule;
    float coupon_rate;
    DayCounter day_counter;
    BusinessDayConvention business_day_convention;
    float redemption;
    std::string issue_date;
};

union Point
{
    struct DepositHelper;
    struct FRAHelper;
    struct FutureHelper;
    struct SwapHelper;
    struct BondHelper;
};

struct TermStructure
{
    std::string id;
    DayCounter day_counter;
    Interpolator interpolator;
    BootstrapTrait bootstrap_trait;
    std::vector<Point> points;
};

struct FixedRateBond
{
    int settlement_days;
    double face_amount;
    double rate;
    DayCounter accrual_day_counter;
    BusinessDayConvention payment_convention;
    double redemption;
    std::string issue_date;
    Schedule schedule;
};

struct FloatingRateBond
{
    int settlement_days;
    double face_amount;
    Schedule schedule;
    Index index;
    DayCounter accrual_day_counter;
    BusinessDayConvention payment_convention;
    int fixing_days;
    double spread;
    bool in_arrears;
    double redemption;
    std::string issue_date;
};

struct PriceFixedRateBond
{
    FixedRateBond fixed_rate_bond;
    std::string discounting_curve;
    Yield yield;
};

struct PriceFixedRateBondRequest
{
    Pricing pricing;
    std::vector<PriceFixedRateBond> bonds;
};

struct PriceFloatingRateBond
{
    FloatingRateBond floating_rate_bond;
    std::string discounting_curve;
    std::string forecasting_curve;
    Yield yield;
};

struct PriceFloatingRateBondRequest
{
    Pricing pricing;
    std::vector<PriceFloatingRateBond> bonds;
};