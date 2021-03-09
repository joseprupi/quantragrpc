#include "flatbuffers/grpc.h"

#include "quantra_structs.h"
#include "responses_generated.h"

structs::PriceFixedRateBondResponse npv_response_to_quantra(const quantra::PriceFixedRateBondResponse *response);