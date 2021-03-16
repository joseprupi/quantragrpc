#include "fbs_to_quantra.h"

std::shared_ptr<structs::PriceFixedRateBondResponse> price_fixed_rate_bond_response_to_quantra(const quantra::PriceFixedRateBondResponse *response)
{
    auto npv_response = std::make_shared<structs::PriceFixedRateBondResponse>();
    //npv_response->npv = response->npv();
    return npv_response;
}