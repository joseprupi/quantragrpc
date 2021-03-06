#include "flatbuffers/grpc.h"

#include "quantra_structs.h"
#include "responses_generated.h"

structs::NPVResponse npv_response_to_quantra(const quantra::NPVResponse *response);