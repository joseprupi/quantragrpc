#include "quantraserver.grpc.fb.h"
#include "quantraserver_generated.h"
#include "fixed_rate_bond_pricing_request.h"

flatbuffers::Offset<quantra::PriceFixedRateBondRequest> bond_request_fbs();