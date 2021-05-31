#include <vector>

#include "quantra_client.h"
#include "request_data.h"

#include <ql/instruments/bonds/zerocouponbond.hpp>
#include <ql/instruments/bonds/floatingratebond.hpp>
#include <ql/pricingengines/bond/discountingbondengine.hpp>
#include <ql/cashflows/couponpricer.hpp>
#include <ql/termstructures/yield/piecewiseyieldcurve.hpp>
#include <ql/termstructures/yield/bondhelpers.hpp>
#include <ql/termstructures/volatility/optionlet/constantoptionletvol.hpp>
#include <ql/indexes/ibor/euribor.hpp>
#include <ql/indexes/ibor/usdlibor.hpp>
#include <ql/time/calendars/target.hpp>
#include <ql/time/calendars/unitedstates.hpp>
#include <ql/time/daycounters/actualactual.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/time/daycounters/thirty360.hpp>

using namespace QuantLib;

int main(int argc, char **argv)
{

    int n_bonds_x_request = 10;
    int n_requests = 1;
    int share_curve = 0;

    double total_quantra_npv = 0;
    double total_quantlib_npv = 0;

    if (argc > 1)
    {
        std::istringstream iss1(argv[1]);
        iss1 >> n_bonds_x_request;

        std::istringstream iss2(argv[2]);
        iss2 >> n_requests;

        std::istringstream iss3(argv[3]);
        iss3 >> share_curve;
    }

    int total_bonds = n_bonds_x_request * n_requests;

    QuantraClient client("grpc.quantra.io:443");

    auto term_structure = term_structure_example();
    auto bond = fixed_rate_bond_example();
    auto request = pricing_request_example();

    std::vector<std::shared_ptr<structs::TermStructure>> term_structures;
    std::vector<std::shared_ptr<structs::PriceFixedRateBond>> bonds;

    if (share_curve == 1)
        term_structures.push_back(term_structure);

    for (int i = 0; i < n_bonds_x_request; i++)
    {
        auto price_fixed_rate_bond = std::make_shared<structs::PriceFixedRateBond>();
        price_fixed_rate_bond->fixed_rate_bond = bond;
        strcpy(price_fixed_rate_bond->discounting_curve, "depos");

        bonds.push_back(price_fixed_rate_bond);

        if (share_curve == 0)
            term_structures.push_back(term_structure);
    }

    request->pricing->curves = term_structures;
    request->bonds = bonds;

    std::vector<std::shared_ptr<structs::PriceFixedRateBondRequest>> requests;

    for (int i = 0; i < n_requests; i++)
    {
        requests.push_back(request);
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    client.PriceFixedRateBondRequest(requests);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Quantra Time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    return 0;
}
