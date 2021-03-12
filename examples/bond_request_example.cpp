#include <vector>

#include "quantra_client.h"
#include "data/fixed_rate_bond_request_quantra.h"

int main()
{

    QuantraClient client("localhost:50051");

    std::shared_ptr<structs::PriceFixedRateBondRequest> bond_pricing_request = request_bond();

    std::vector<std::shared_ptr<structs::PriceFixedRateBondRequest>> requests;
    requests.push_back(bond_pricing_request);

    client.PriceFixedRateBondRequest(requests);

    return 0;
}