#ifndef QUANTRASERVER_FIXEDRATEBONDPRICINGREQUEST_H
#define QUANTRASERVER_FIXEDRATEBONDPRICINGREQUEST_H

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

#include "responses_generated.h"
#include "requests_generated.h"
#include "common_parser.h"
#include "fixed_rate_bond_parser.h"

class fixedRateBondPricingRequest
{
public:
    std::shared_ptr<quantra::responses::FixedRatePricingResponse> request(const quantra::PriceFixedRateBond *request);
};

#endif //QUANTRASERVER_FIXEDRATEBONDPRICINGREQUEST_H