#include "fixed_rate_bond_pricing_request.h"
#include <map>

float FixedRateBondPricingRequest::request(const quantra::PriceFixedRateBondRequest *request)
{

    // Define the parsers used for this request
    FixedRateBondParser bond_parser = FixedRateBondParser();
    //YieldParser yield_parser = YieldParser();
    TermStructureParser term_structure_parser = TermStructureParser();

    // Read the pricing information
    auto pricing = request->pricing();

    // Set the evaluation date from the pricing entity
    Date as_of_date = DateToQL(pricing->as_of_date()->c_str());
    Settings::instance().evaluationDate() = as_of_date;

    // Create the different term structures from the pricing entity
    auto curves = pricing->curves();
    std::map<std::string, std::shared_ptr<PricingEngine>> term_structures;
    for (auto it = curves->begin(); it != curves->end(); it++)
    {

        RelinkableHandle<YieldTermStructure> discounting_term_structure;
        std::shared_ptr<PricingEngine> bond_engine(new QuantLib::DiscountingBondEngine(discounting_term_structure));
        std::shared_ptr<YieldTermStructure> term_structure = term_structure_parser.parse(*it);
        discounting_term_structure.linkTo(term_structure);
        term_structures.insert(std::make_pair(it->id()->str(), bond_engine));
    }

    auto bond_pricings = request->bonds();

    for (auto it = bond_pricings->begin(); it != bond_pricings->end(); it++)
    {

        auto engine = term_structures.find(it->discounting_curve()->str());
        if (engine == term_structures.end())
        {
            //handle the error
        }
        else
        {
            std::shared_ptr<QuantLib::FixedRateBond> bond = bond_parser.parse(it->fixed_rate_bond());
            bond->setPricingEngine(engine->second);
            return bond->NPV();
        }
    }
}