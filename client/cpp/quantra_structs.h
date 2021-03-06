#ifndef QUANTRA_STRUCTS_H
#define QUANTRA_STRUCTS_H

#include "enums_generated.h"

using namespace quantra::enums;

namespace structs
{

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
    struct Point;
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
        char as_of_date[11];
        std::vector<TermStructure> curves;
    };

    struct Schedule
    {
        Calendar calendar;
        char effective_date[11];
        char termination_date[11];
        Frequency frequency;
        BusinessDayConvention convention;
        BusinessDayConvention termination_date_convention;
        DateGenerationRule date_generation_rule;
        bool end_of_mont;
    };

    struct Fixing
    {
        char date[11];
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
        int tenor_number;
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
        char future_start_date[11];
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
        char issue_date[11];
    };

    enum PointType
    {
        Deposit,
        FRA,
        Future,
        Swap,
        Bond
    };

    struct Point
    {
        PointType point_type;
        union
        {
            DepositHelper deposit_helper;
            FRAHelper FRA_helper;
            FutureHelper future_helper;
            SwapHelper swap_helper;
            BondHelper bond_helper;
        };
    };

    struct TermStructure
    {
        char id[11];
        DayCounter day_counter;
        Interpolator interpolator;
        BootstrapTrait bootstrap_trait;
        char as_of_date[11];
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
        char issue_date[11];
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
        char discounting_curve[11];
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
        char discounting_curve[11];
        char forecasting_curve[11];
        Yield yield;
    };

    struct PriceFloatingRateBondRequest
    {
        Pricing pricing;
        std::vector<PriceFloatingRateBond> bonds;
    };

    struct NPVResponse
    {
        float npv;
    };

}

#endif //QUANTRA_STRUCTS_H