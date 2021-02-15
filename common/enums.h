#include <ql/quantlib.hpp>

#include "enums_generated.h"

#ifndef ENUMS_H
#define ENUMS_H

QuantLib::TimeUnit TimeUnitToQL(quantra::enums::TimeUnit timeUnit)
{

    switch (timeUnit)
    {
    case quantra::enums::TimeUnit_Days:
        return QuantLib::Days;
    case quantra::enums::TimeUnit_Weeks:
        return QuantLib::Weeks;
    case quantra::enums::TimeUnit_Months:
        return QuantLib::Months;
    case quantra::enums::TimeUnit_Years:
        return QuantLib::Years;
    case quantra::enums::TimeUnit_Hours:
        return QuantLib::Hours;
    case quantra::enums::TimeUnit_Minutes:
        return QuantLib::Minutes;
    case quantra::enums::TimeUnit_Seconds:
        return QuantLib::Seconds;
    case quantra::enums::TimeUnit_Milliseconds:
        return QuantLib::Milliseconds;
    case quantra::enums::TimeUnit_Microseconds:
        return QuantLib::Microseconds;
    }
}

QuantLib::Calendar CalendarToQL(quantra::enums::Calendar calendar)
{

    switch (calendar)
    {
    case quantra::enums::Calendar_Argentina:
        return QuantLib::Argentina();
    case quantra::enums::Calendar_Australia:
        return QuantLib::Australia();
    case quantra::enums::Calendar_BespokeCalendar:
        return QuantLib::BespokeCalendar();
    case quantra::enums::Calendar_Brazil:
        return QuantLib::Brazil();
    case quantra::enums::Calendar_Canada:
        return QuantLib::Canada();
    case quantra::enums::Calendar_China:
        return QuantLib::China();
    case quantra::enums::Calendar_CzechRepublic:
        return QuantLib::CzechRepublic();
    case quantra::enums::Calendar_Denmark:
        return QuantLib::Denmark();
    case quantra::enums::Calendar_Finland:
        return QuantLib::Finland();
    case quantra::enums::Calendar_Germany:
        return QuantLib::Germany();
    case quantra::enums::Calendar_HongKong:
        return QuantLib::HongKong();
    case quantra::enums::Calendar_Hungary:
        return QuantLib::Hungary();
    case quantra::enums::Calendar_Iceland:
        return QuantLib::Iceland();
    case quantra::enums::Calendar_India:
        return QuantLib::India();
    case quantra::enums::Calendar_Indonesia:
        return QuantLib::Indonesia();
    case quantra::enums::Calendar_Israel:
        return QuantLib::Israel();
    case quantra::enums::Calendar_Italy:
        return QuantLib::Italy();
    case quantra::enums::Calendar_Japan:
        return QuantLib::Japan();
    case quantra::enums::Calendar_Mexico:
        return QuantLib::Mexico();
    case quantra::enums::Calendar_NewZealand:
        return QuantLib::NewZealand();
    case quantra::enums::Calendar_Norway:
        return QuantLib::Norway();
    case quantra::enums::Calendar_NullCalendar:
        return QuantLib::NullCalendar();
    case quantra::enums::Calendar_Poland:
        return QuantLib::Poland();
    case quantra::enums::Calendar_Romania:
        return QuantLib::Romania();
    case quantra::enums::Calendar_Russia:
        return QuantLib::Russia();
    case quantra::enums::Calendar_SaudiArabia:
        return QuantLib::SaudiArabia();
    case quantra::enums::Calendar_Singapore:
        return QuantLib::Singapore();
    case quantra::enums::Calendar_Slovakia:
        return QuantLib::Slovakia();
    case quantra::enums::Calendar_SouthAfrica:
        return QuantLib::SouthAfrica();
    case quantra::enums::Calendar_SouthKorea:
        return QuantLib::SouthKorea();
    case quantra::enums::Calendar_Sweden:
        return QuantLib::Sweden();
    case quantra::enums::Calendar_Switzerland:
        return QuantLib::Switzerland();
    case quantra::enums::Calendar_Taiwan:
        return QuantLib::Taiwan();
    case quantra::enums::Calendar_TARGET:
        return QuantLib::TARGET();
    case quantra::enums::Calendar_Turkey:
        return QuantLib::Turkey();
    case quantra::enums::Calendar_Ukraine:
        return QuantLib::Ukraine();
    case quantra::enums::Calendar_UnitedKingdom:
        return QuantLib::UnitedKingdom();
    case quantra::enums::Calendar_UnitedStates:
        return QuantLib::UnitedStates();
    case quantra::enums::Calendar_UnitedStatesSettlement:
        return QuantLib::UnitedStates(QuantLib::UnitedStates::Settlement);
    case quantra::enums::Calendar_UnitedStatesNYSE:
        return QuantLib::UnitedStates(QuantLib::UnitedStates::NYSE);
    case quantra::enums::Calendar_UnitedStatesGovernmentBond:
        return QuantLib::UnitedStates(QuantLib::UnitedStates::GovernmentBond);
    case quantra::enums::Calendar_UnitedStatesNERC:
        return QuantLib::UnitedStates(QuantLib::UnitedStates::NERC);
    case quantra::enums::Calendar_WeekendsOnly:
        return QuantLib::WeekendsOnly();
    }
}

QuantLib::BusinessDayConvention ConventionToQL(quantra::enums::BusinessDayConvention dayConvention)
{

    switch (dayConvention)
    {
    case quantra::enums::BusinessDayConvention_Following:
        return QuantLib::Following;
    case quantra::enums::BusinessDayConvention_ModifiedFollowing:
        return QuantLib::ModifiedFollowing;
    case quantra::enums::BusinessDayConvention_Preceding:
        return QuantLib::Preceding;
    case quantra::enums::BusinessDayConvention_ModifiedPreceding:
        return QuantLib::ModifiedPreceding;
    case quantra::enums::BusinessDayConvention_Unadjusted:
        return QuantLib::Unadjusted;
    case quantra::enums::BusinessDayConvention_HalfMonthModifiedFollowing:
        return QuantLib::HalfMonthModifiedFollowing;
    case quantra::enums::BusinessDayConvention_Nearest:
        return QuantLib::Nearest;
    }
}

QuantLib::DayCounter DayCounterToQL(quantra::enums::DayCounter dayCounter)
{

    switch (dayCounter)
    {
    case quantra::enums::DayCounter_Actual360:
        return QuantLib::Actual360();
    case quantra::enums::DayCounter_Actual365Fixed:
        return QuantLib::Actual365Fixed();
    case quantra::enums::DayCounter_Actual365NoLeap:
        return QuantLib::Actual365Fixed();
    case quantra::enums::DayCounter_ActualActual:
        return QuantLib::ActualActual();
    case quantra::enums::DayCounter_ActualActualISMA:
        return QuantLib::ActualActual(QuantLib::ActualActual::ISMA);
    case quantra::enums::DayCounter_ActualActualBond:
        return QuantLib::ActualActual(QuantLib::ActualActual::Bond);
    case quantra::enums::DayCounter_ActualActualISDA:
        return QuantLib::ActualActual(QuantLib::ActualActual::ISDA);
    case quantra::enums::DayCounter_ActualActualHistorical:
        return QuantLib::ActualActual(QuantLib::ActualActual::Historical);
    case quantra::enums::DayCounter_ActualActual365:
        return QuantLib::ActualActual(QuantLib::ActualActual::Actual365);
    case quantra::enums::DayCounter_ActualActualAFB:
        return QuantLib::ActualActual(QuantLib::ActualActual::AFB);
    case quantra::enums::DayCounter_ActualActualEuro:
        return QuantLib::ActualActual(QuantLib::ActualActual::Euro);
    case quantra::enums::DayCounter_Business252:
        return QuantLib::Business252();
    case quantra::enums::DayCounter_One:
        return QuantLib::OneDayCounter();
    case quantra::enums::DayCounter_Simple:
        return QuantLib::SimpleDayCounter();
    case quantra::enums::DayCounter_Thirty360:
        return QuantLib::Thirty360();
    }
}

QuantLib::Frequency FrequencyToQL(quantra::enums::Frequency frequency)
{

    switch (frequency)
    {
    case quantra::enums::Frequency_NoFrequency:
        return QuantLib::NoFrequency;
    case quantra::enums::Frequency_Once:
        return QuantLib::Once;
    case quantra::enums::Frequency_Annual:
        return QuantLib::Annual;
    case quantra::enums::Frequency_Semiannual:
        return QuantLib::Semiannual;
    case quantra::enums::Frequency_EveryFourthMonth:
        return QuantLib::EveryFourthMonth;
    case quantra::enums::Frequency_Quarterly:
        return QuantLib::Quarterly;
    case quantra::enums::Frequency_Bimonthly:
        return QuantLib::Bimonthly;
    case quantra::enums::Frequency_Monthly:
        return QuantLib::Monthly;
    case quantra::enums::Frequency_EveryFourthWeek:
        return QuantLib::EveryFourthWeek;
    case quantra::enums::Frequency_Biweekly:
        return QuantLib::Biweekly;
    case quantra::enums::Frequency_Weekly:
        return QuantLib::Weekly;
    case quantra::enums::Frequency_Daily:
        return QuantLib::Daily;
    case quantra::enums::Frequency_OtherFrequency:
        return QuantLib::OtherFrequency;
    }
}

std::shared_ptr<QuantLib::IborIndex> IborToQL(quantra::enums::Ibor ibor)
{

    std::shared_ptr<QuantLib::IborIndex> index;

    switch (ibor)
    {
    case quantra::enums::Ibor_EuriborSW:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::EuriborSW());
        break;
    case quantra::enums::Ibor_Euribor2W:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor2W());
        break;
    case quantra::enums::Ibor_Euribor3W:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor3W());
        break;
    case quantra::enums::Ibor_Euribor1M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor1M());
        break;
    case quantra::enums::Ibor_Euribor2M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor2M());
        break;
    case quantra::enums::Ibor_Euribor3M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor3M());
        break;
    case quantra::enums::Ibor_Euribor4M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor4M());
        break;
    case quantra::enums::Ibor_Euribor5M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor5M());
        break;
    case quantra::enums::Ibor_Euribor6M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor6M());
        break;
    case quantra::enums::Ibor_Euribor7M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor7M());
        break;
    case quantra::enums::Ibor_Euribor8M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor8M());
        break;
    case quantra::enums::Ibor_Euribor9M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor9M());
        break;
    case quantra::enums::Ibor_Euribor10M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor10M());
        break;
    case quantra::enums::Ibor_Euribor11M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor11M());
        break;
    case quantra::enums::Ibor_Euribor1Y:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor1Y());
        break;
    case quantra::enums::Ibor_Euribor365_SW:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_SW());
        break;
    case quantra::enums::Ibor_Euribor365_2W:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_2W());
        break;
    case quantra::enums::Ibor_Euribor365_3W:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_3W());
        break;
    case quantra::enums::Ibor_Euribor365_1M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_1M());
        break;
    case quantra::enums::Ibor_Euribor365_2M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_2M());
        break;
    case quantra::enums::Ibor_Euribor365_3M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_3M());
        break;
    case quantra::enums::Ibor_Euribor365_4M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_4M());
        break;
    case quantra::enums::Ibor_Euribor365_5M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_5M());
        break;
    case quantra::enums::Ibor_Euribor365_6M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_6M());
        break;
    case quantra::enums::Ibor_Euribor365_7M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_7M());
        break;
    case quantra::enums::Ibor_Euribor365_8M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_8M());
        break;
    case quantra::enums::Ibor_Euribor365_9M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_9M());
        break;
    case quantra::enums::Ibor_Euribor365_10M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_10M());
        break;
    case quantra::enums::Ibor_Euribor365_11M:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_11M());
        break;
    case quantra::enums::Ibor_Euribor365_1Y:
        index = std::shared_ptr<QuantLib::IborIndex>(new QuantLib::Euribor365_1Y());
        break;
    }
    return index;
}

QuantLib::DateGeneration::Rule DateGenerationToQL(quantra::enums::DateGenerationRule dateGeneration)
{

    switch (dateGeneration)
    {
    case quantra::enums::DateGenerationRule_Backward:
        return QuantLib::DateGeneration::Backward;
    case quantra::enums::DateGenerationRule_Forward:
        return QuantLib::DateGeneration::Forward;
    case quantra::enums::DateGenerationRule_Zero:
        return QuantLib::DateGeneration::Zero;
    case quantra::enums::DateGenerationRule_ThirdWednesday:
        return QuantLib::DateGeneration::ThirdWednesday;
    case quantra::enums::DateGenerationRule_Twentieth:
        return QuantLib::DateGeneration::Twentieth;
    case quantra::enums::DateGenerationRule_TwentiethIMM:
        return QuantLib::DateGeneration::TwentiethIMM;
    case quantra::enums::DateGenerationRule_OldCDS:
        return QuantLib::DateGeneration::OldCDS;
    case quantra::enums::DateGenerationRule_CDS:
        return QuantLib::DateGeneration::CDS;
    }
}

QuantLib::Compounding CompoundingToQL(quantra::enums::Compounding compounding)
{

    switch (compounding)
    {
    case quantra::enums::Compounding_Compounded:
        return QuantLib::Compounded;
    case quantra::enums::Compounding_Continuous:
        return QuantLib::Continuous;
    case quantra::enums::Compounding_Simple:
        return QuantLib::Simple;
    case quantra::enums::Compounding_SimpleThenCompounded:
        return QuantLib::SimpleThenCompounded;
    }
}

#endif //ENUMS_H