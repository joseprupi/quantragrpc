#include "flatbuffers/grpc.h"

#include "quantra_structs.h"
#include "responses_generated.h"

std::shared_ptr<structs::PriceFixedRateBondResponse> price_fixed_rate_bond_response_to_quantra(const quantra::PriceFixedRateBondResponse *response);