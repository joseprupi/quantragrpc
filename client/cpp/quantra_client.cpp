#include "quantra_client.h"

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

QuantraClient::QuantraClient(std::string addr)
{
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(
        addr, grpc::InsecureChannelCredentials());
    this->stub_ = std::make_unique<quantra::QuantraServer::Stub>(channel);
}

void QuantraClient::PriceFixedRateBondRequestCall(structs::PriceFixedRateBondRequest &request, int request_tag)
{
    std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder = std::make_shared<flatbuffers::grpc::MessageBuilder>();

    auto bond_request = price_fixe_rate_bond_request_to_fbs(builder, request);
    builder->Finish(bond_request);

    auto request_msg = builder->ReleaseMessage<quantra::PriceFixedRateBondRequest>();

    AsyncClientCall *call = new AsyncClientCall;
    call->request_pos = request_tag;

    call->response_reader =
        stub_->PrepareAsyncPriceFixedRateBond(&call->context, request_msg, &cq_);

    call->response_reader->StartCall();

    call->response_reader->Finish(&call->reply, &call->status, (void *)call);
}

void QuantraClient::PriceFixedRateBondRequest(std::vector<structs::PriceFixedRateBondRequest> request)
{
    this->responses.resize(request.size());
    std::thread thread_ = std::thread(&QuantraClient::AsyncCompleteRpc, this, request.size());

    int request_tag = 0;
    for (auto it = request.begin(); it != request.end(); it++)
    {
        this->PriceFixedRateBondRequestCall(*it, request_tag);
        request_tag += 1;
    }

    thread_.join();
}

void QuantraClient::AsyncCompleteRpc(int request_size)
{
    void *got_tag;
    bool ok = false;

    int req_count = 0;

    while (cq_.Next(&got_tag, &ok))
    {
        AsyncClientCall *call = static_cast<AsyncClientCall *>(got_tag);

        GPR_ASSERT(ok);

        if (call->status.ok())
        {
            const quantra::PriceFixedRateBondResponse *response = call->reply.GetRoot();
        }
        else
        {
            std::cout << "RPC code: " << call->status.error_code() << std::endl;
            std::cout << "RPC message: " << call->status.error_message() << std::endl;
            std::cout << "Error details: " << call->status.error_details() << std::endl;
        }

        delete call;

        req_count += 1;
        if (req_count == request_size)
            break;
    }
}