#include "fixed_rate_bond_pricing_request.h"

std::shared_ptr<quantra::responses::FixedRatePricingResponse> fixedRateBondPricingRequest::request(const quantra::PriceFixedRateBond *request)
{
    FixedRateBondParser bond_parser = FixedRateBondParser();
    PricingParser pricing_parser = PricingParser();
    YieldParser pricing_parser = YieldParser();

    std::shared_ptr<QuantLib::FixedRateBond> bond = bond_parser.parse(request->fixed_rate_bond());
    std::shared_ptr<YieldTermStructure> =
}