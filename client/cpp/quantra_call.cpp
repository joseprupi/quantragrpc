#include "quantra_call.h"

std::shared_ptr<flatbuffers::grpc::MessageBuilder> PriceFixedRateBondData::JSONParser_(std::string json_str)
{
    return this->json_parser->PriceFixedRateBondRequestToFBS(json_str);
}

flatbuffers::Offset<quantra::PriceFixedRateBondRequest> PriceFixedRateBondData::QuantraToFBS(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder,
                                                                                             std::shared_ptr<structs::PriceFixedRateBondRequest> request_struct)
{
    return price_fixe_rate_bond_request_to_fbs(builder, request_struct);
}

void PriceFixedRateBondData::PrepareAsync(AsyncClientCall *call)
{
    call->response_reader =
        this->stub_->PrepareAsyncPriceFixedRateBond(&call->context, request_msg, &this->cq_);
}

std::shared_ptr<std::vector<std::shared_ptr<structs::PriceFixedRateBondValues>>> PriceFixedRateBondData::FBSToQuantra(const quantra::PriceFixedRateBondResponse *response)
{
    return price_fixed_rate_bond_response_to_quantra(response);
}