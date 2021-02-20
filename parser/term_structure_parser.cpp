#include "term_structure_parser.h"

using namespace quantra;

std::shared_ptr<YieldTermStructure> TermStructureParser::parse(const quantra::TermStructure *ts)
{
    auto points = ts->points();
    auto types = ts->points_type();

    TermStructurePointParser tsparser = TermStructurePointParser();
    std::vector<std::shared_ptr<RateHelper>> instruments;

    for (int i = 0; i < points->size(); i++)
    {
        auto point = points->Get(i);
        auto type = types->Get(i);
        std::shared_ptr<RateHelper> rate_helper = tsparser.parse(type, point);
        instruments.push_back(rate_helper);
    }

    std::shared_ptr<YieldTermStructure> termStructure;
    double tolerance = 1.0e-15;

    switch (ts->interpolator())
    {
    case enums::Interpolator_BackwardFlat:
        switch (ts->bootstrap_trait())
        {

        case enums::BootstrapTrait_Discount:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<Discount, BackwardFlat>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    PiecewiseYieldCurve<Discount, BackwardFlat>::bootstrap_type(tolerance)));
            break;

        case enums::BootstrapTrait_ZeroRate:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<ZeroYield, BackwardFlat>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    PiecewiseYieldCurve<ZeroYield, BackwardFlat>::bootstrap_type(tolerance)));
            break;

        case enums::BootstrapTrait_FwdRate:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<ForwardRate, BackwardFlat>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    PiecewiseYieldCurve<ForwardRate, BackwardFlat>::bootstrap_type(tolerance)));
            break;
        }
        break;

    case enums::Interpolator_ForwardFlat:
        switch (ts->bootstrap_trait())
        {

        case enums::BootstrapTrait_Discount:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<Discount, ForwardFlat>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    PiecewiseYieldCurve<Discount, ForwardFlat>::bootstrap_type(tolerance)));
            break;

        case enums::BootstrapTrait_ZeroRate:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<ZeroYield, ForwardFlat>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    PiecewiseYieldCurve<ZeroYield, ForwardFlat>::bootstrap_type(tolerance)));
            break;

        case enums::BootstrapTrait_FwdRate:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<ForwardRate, ForwardFlat>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    PiecewiseYieldCurve<ForwardRate, ForwardFlat>::bootstrap_type(tolerance)));
            break;
        }
        break;

    case enums::Interpolator_Linear:
        switch (ts->bootstrap_trait())
        {

        case enums::BootstrapTrait_Discount:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<Discount, Linear>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    PiecewiseYieldCurve<Discount, Linear>::bootstrap_type(tolerance)));
            break;

        case enums::BootstrapTrait_ZeroRate:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<ZeroYield, Linear>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    PiecewiseYieldCurve<ZeroYield, Linear>::bootstrap_type(tolerance)));
            break;

        case enums::BootstrapTrait_FwdRate:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<ForwardRate, Linear>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    PiecewiseYieldCurve<ForwardRate, Linear>::bootstrap_type(tolerance)));
            break;
        }
        break;

    case enums::Interpolator_LogLinear:
        switch (ts->bootstrap_trait())
        {

        case enums::BootstrapTrait_Discount:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<Discount, LogLinear>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    PiecewiseYieldCurve<Discount, LogLinear>::bootstrap_type(tolerance)));
            break;

        case enums::BootstrapTrait_ZeroRate:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<ZeroYield, LogLinear>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    PiecewiseYieldCurve<ZeroYield, LogLinear>::bootstrap_type(tolerance)));
            break;

        case enums::BootstrapTrait_FwdRate:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<ForwardRate, LogLinear>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    PiecewiseYieldCurve<ForwardRate, LogLinear>::bootstrap_type(tolerance)));
            break;
        }
        break;

    case enums::Interpolator_LogCubic:

        switch (ts->bootstrap_trait())
        {

        case enums::BootstrapTrait_Discount:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<Discount, LogCubic>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    MonotonicLogCubic()));
            break;

        case enums::BootstrapTrait_ZeroRate:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<ZeroYield, LogCubic>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    MonotonicLogCubic()));
            break;

        case enums::BootstrapTrait_FwdRate:

            termStructure = std::shared_ptr<YieldTermStructure>(
                new PiecewiseYieldCurve<ForwardRate, LogCubic>(
                    DateToQL(ts->as_of_date()->str()), instruments,
                    DayCounterToQL(ts->day_counter()),
                    MonotonicLogCubic()));
            break;
        }
        break;
    }

    return termStructure;
}