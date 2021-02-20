#ifndef QUANTRASERVER_FIXEDRATEBONDPRICINGREQUEST_H
#define QUANTRASERVER_FIXEDRATEBONDPRICINGREQUEST_H

#include <ql/qldefines.hpp>

class fixedRateBondPricingRequest
{
public:
    std::shared_ptr<flatbuffers::grpc::Message<quantra::BondPricingReply>> ProcessRequest(flatbuffers::grpc::Message<quantra::BondPricingRequest> request);
};

#endif //QUANTRASERVER_FIXEDRATEBONDPRICINGREQUEST_H