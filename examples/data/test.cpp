#include "test.h"

void bond_request_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder)
{

    auto price_request = request_bond();
    auto bond_request = price_fixe_rate_bond_request_to_fbs(builder, price_request);
    builder->Finish(bond_request);

    return;
}