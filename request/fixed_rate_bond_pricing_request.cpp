#include "fixed_rate_bond_pricing_request.h"

//std::shared_ptr<quantra::responses::FixedRatePricingResponse> fixedRateBondPricingRequest::request(const quantra::PriceFixedRateBond *request)
float FixedRateBondPricingRequest::request(const quantra::PriceFixedRateBond *request)
{
    FixedRateBondParser bond_parser = FixedRateBondParser();
    PricingParser pricing_parser = PricingParser();
    YieldParser yield_parser = YieldParser();
    TermStructureParser term_structure_parser = TermStructureParser();

    std::shared_ptr<QuantLib::FixedRateBond> bond = bond_parser.parse(request->fixed_rate_bond());
    std::shared_ptr<YieldStruct> yield = yield_parser.parse(request->yield());
    std::shared_ptr<PricingStruct> pricing = pricing_parser.parse(request->pricing());
    std::shared_ptr<YieldTermStructure> term_structure = term_structure_parser.parse(request->term_structure());

    RelinkableHandle<YieldTermStructure> discounting_term_structure;
    std::shared_ptr<PricingEngine> bond_engine(new QuantLib::DiscountingBondEngine(discounting_term_structure));
    //std::shared_ptr<PricingEngine> bond_engine = std::make_shared<QuantLib::PricingEngine>(discounting_term_structure);
    discounting_term_structure.linkTo(term_structure);
    bond->setPricingEngine(bond_engine);

    return bond->NPV();
}