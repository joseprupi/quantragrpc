#include "fbs_to_quantra.h"

structs::NPVResponse npv_response_to_quantra(const quantra::NPVResponse *response)
{
    structs::NPVResponse npv_response;
    npv_response.npv = response->npv();
    return npv_response;
}