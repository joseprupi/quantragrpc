#ifndef QUANTRASERVER_COMMONPARSER_H
#define QUANTRASERVER_COMMONPARSER_H

#include <ql/qldefines.hpp>
#include <ql/termstructures/yield/piecewiseyieldcurve.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>
#include <ql/termstructures/yield/ratehelpers.hpp>
#include <ql/termstructures/yield/oisratehelper.hpp>
#include <ql/pricingengines/swap/discountingswapengine.hpp>
#include <ql/indexes/ibor/eonia.hpp>
#include <ql/indexes/ibor/euribor.hpp>
#include <ql/time/imm.hpp>
#include <ql/time/calendars/target.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/time/daycounters/thirty360.hpp>
#include <ql/time/daycounters/actualactual.hpp>
#include <ql/math/interpolations/cubicinterpolation.hpp>
#include <ql/math/interpolations/loginterpolation.hpp>

#include "common_generated.h"
#include "enums.h"
#include "common.h"

using namespace QuantLib;
using namespace quantra;

struct PricingStruct
{
    Date as_of_date;
};

class PricingParser
{

private:
public:
    std::shared_ptr<PricingStruct> parse(const quantra::Pricing *p);
};

class ScheduleParser
{

private:
public:
    std::shared_ptr<QuantLib::Schedule> parse(const quantra::Schedule *p);
};

#endif //QUANTRASERVER_COMMONPARSER_H