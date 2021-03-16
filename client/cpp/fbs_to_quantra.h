#include "flatbuffers/grpc.h"

#include "quantra_structs.h"
#include "responses_generated.h"

std::shared_ptr<std::vector<std::shared_ptr<structs::PriceFixedRateBondValues>>> price_fixed_rate_bond_response_to_quantra(const quantra::PriceFixedRateBondResponse *response);