#include "fbs_to_quantra.h"

structs::PriceFixedRateBondResponse price_fixed_rate_bond_response_to_quantra(const quantra::PriceFixedRateBondResponse *response)
{
    structs::PriceFixedRateBondResponse npv_response;
    npv_response.npv = response->npv();
    return npv_response;
}