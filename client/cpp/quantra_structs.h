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
        quantra::enums::DayCounter day_counter;
        quantra::enums::Compounding compounding;
        quantra::enums::Frequency frequency;
    };

    struct Pricing
    {
        char as_of_date[11];
        std::vector<TermStructure> curves;
    };

    struct Schedule
    {
        quantra::enums::Calendar calendar;
        char effective_date[11];
        char termination_date[11];
        quantra::enums::Frequency frequency;
        quantra::enums::BusinessDayConvention convention;
        quantra::enums::BusinessDayConvention termination_date_convention;
        quantra::enums::DateGenerationRule date_generation_rule;
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
        quantra::enums::TimeUnit period_time_unit;
        int settlement_days;
        quantra::enums::Calendar calendar;
        quantra::enums::BusinessDayConvention business_day_convention;
        bool end_of_month;
        quantra::enums::DayCounter day_counter;
        std::vector<Fixing> fixings;
    };

    struct DepositHelper
    {
        float rate;
        quantra::enums::TimeUnit tenor_time_unit;
        int tenor_number;
        int fixing_days;
        quantra::enums::Calendar calendar;
        quantra::enums::BusinessDayConvention business_day_convention;
        quantra::enums::DayCounter day_counter;
    };

    struct FRAHelper
    {
        float rate;
        int months_to_start;
        int months_to_end;
        int fixing_days;
        quantra::enums::Calendar calendar;
        quantra::enums::BusinessDayConvention business_day_convention;
        quantra::enums::DayCounter day_counter;
    };

    struct FutureHelper
    {
        float rate;
        char future_start_date[11];
        int future_months;
        quantra::enums::Calendar calendar;
        quantra::enums::BusinessDayConvention business_day_convention;
        quantra::enums::DayCounter day_counter;
    };

    struct SwapHelper
    {
        float rate;
        quantra::enums::TimeUnit tenor_time_unit;
        int tenor_number;
        quantra::enums::Calendar calendar;
        quantra::enums::Frequency sw_fixed_leg_frequency;
        quantra::enums::BusinessDayConvention sw_fixed_leg_convention;
        quantra::enums::DayCounter sw_fixed_leg_day_counter;
        quantra::enums::Ibor sw_floating_leg_index;
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
        quantra::enums::DayCounter day_counter;
        quantra::enums::BusinessDayConvention business_day_convention;
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
        quantra::enums::DayCounter day_counter;
        quantra::enums::Interpolator interpolator;
        quantra::enums::BootstrapTrait bootstrap_trait;
        char as_of_date[11];
        std::vector<Point> points;
    };

    struct FixedRateBond
    {
        int settlement_days;
        double face_amount;
        double rate;
        quantra::enums::DayCounter accrual_day_counter;
        quantra::enums::BusinessDayConvention payment_convention;
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
        quantra::enums::DayCounter accrual_day_counter;
        quantra::enums::BusinessDayConvention payment_convention;
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