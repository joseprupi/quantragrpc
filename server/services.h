#include "quantraserver.grpc.fb.h"
#include "quantraserver_generated.h"

#include "fixed_rate_bond_pricing_request.h"
#include "floating_rate_bond_pricing_request.h"
#include "price_fixed_rate_bond_request_generated.h"
#include "price_floating_rate_bond_request_generated.h"

#include <grpcpp/grpcpp.h>

#include <iostream>
#include <memory>
#include <string>
#include <sstream>

class PriceFixedRateBondData : public CallDataGeneric<quantra::PriceFixedRateBondRequest, FixedRateBondPricingRequest, PriceFixedRateBondResponse, PriceFixedRateBondResponseBuilder>
{
public:
    PriceFixedRateBondData(QuantraServer::AsyncService *service, grpc::ServerCompletionQueue *cq);
    void RequestCall();
};

class PriceFloatingRateBondData : public CallDataGeneric<quantra::PriceFloatingRateBondRequest, FloatingRateBondPricingRequest, PriceFloatingRateBondResponse, PriceFloatingRateBondResponseBuilder>
{
public:
    PriceFloatingRateBondData(QuantraServer::AsyncService *service, grpc::ServerCompletionQueue *cq);
    void RequestCall();
};
