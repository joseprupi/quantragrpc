#ifndef QUANTRASERVER_FIXEDRATEBONDPRICINGREQUEST_H
#define QUANTRASERVER_FIXEDRATEBONDPRICINGREQUEST_H

#include "quantraserver.grpc.fb.h"
#include "quantraserver_generated.h"

#include <grpcpp/grpcpp.h>

#include <ql/qldefines.hpp>

class fixedRateBondPricingRequest
{
public:
    std::shared_ptr<flatbuffers::grpc::Message<quantra::BondPricingReply>> ProcessRequest(flatbuffers::grpc::Message<quantra::BondPricingRequest> request);
};

#endif //QUANTRASERVER_FIXEDRATEBONDPRICINGREQUEST_H