#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <chrono>

#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>
#include <thread>

#include "quantra_to_fbs.h"
#include "json_to_fbs.h"
#include "fbs_to_quantra.h"
#include "quantraserver.grpc.fb.h"
#include "fixed_rate_bond_response_generated.h"
#include "floating_rate_bond_response_generated.h"

struct json_response
{
    bool ok;
    std::shared_ptr<std::string> response_value;
};

class QuantraClient
{
public:
    explicit QuantraClient(){};
    explicit QuantraClient(std::string addr, bool secured);
    explicit QuantraClient(std::shared_ptr<quantra::QuantraServer::Stub> stub_);

    std::shared_ptr<json_response> PriceFloatingRateBondRequestJSON(std::string json);
    void PriceFloatingRateBondRequestCall(std::shared_ptr<structs::PriceFloatingRateBondRequest> request, int request_tag);
    void PriceFloatingRateBondRequest(std::vector<std::shared_ptr<structs::PriceFloatingRateBondRequest>> request);

    std::shared_ptr<json_response> PriceFixedRateBondRequestJSON(std::string json);
    void PriceFixedRateBondRequestCall(std::shared_ptr<structs::PriceFixedRateBondRequest> request, int request_tag);
    void PriceFixedRateBondRequest(std::vector<std::shared_ptr<structs::PriceFixedRateBondRequest>> request);

    void AsyncCompleteRpc(int request_size);
    std::vector<std::shared_ptr<std::vector<std::shared_ptr<structs::PriceFixedRateBondValues>>>> responses;
    std::vector<std::shared_ptr<json_response>> json_responses;

    std::shared_ptr<quantra::QuantraServer::Stub> ReturnStub() { return this->stub_; }

private:
    struct AsyncClientCall
    {

        flatbuffers::grpc::Message<quantra::PriceFixedRateBondResponse> reply;
        flatbuffers::grpc::Message<quantra::Error> error_details;
        grpc::ClientContext context;
        grpc::Status status;
        int request_pos;
        std::unique_ptr<grpc::ClientAsyncResponseReader<flatbuffers::grpc::Message<quantra::PriceFixedRateBondResponse>>> response_reader;
        bool json = false;
    };

    std::shared_ptr<JSONParser> json_parser = std::make_shared<JSONParser>();
    std::shared_ptr<quantra::QuantraServer::Stub> stub_;
    grpc::CompletionQueue cq_;
};

template <class Struct, class Request, class Response>
class QuantraCall
{
public:
    QuantraCall(std::shared_ptr<quantra::QuantraServer::Stub> stub_, grpc::CompletionQueue cq_)
    {
    }
    virtual void PrepareAsync(std::unique_ptr<grpc::ClientAsyncResponseReader<flatbuffers::grpc::Message<Response>>> response_reader, std::shared_ptr<quantra::QuantraServer::Stub> stub_) = 0;
    void Call(std::shared_ptr<Struct> request, int request_tag)
    {
        std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder = std::make_shared<flatbuffers::grpc::MessageBuilder>();

        auto bond_request = price_fixe_rate_bond_request_to_fbs(builder, request);
        builder->Finish(bond_request);

        auto request_msg = builder->ReleaseMessage<Request>();

        AsyncClientCall *call = new AsyncClientCall;
        call->request_pos = request_tag;

        call->response_reader =
            this->PrepareAsync(&call->context, request_msg, &cq_);

        call->response_reader->StartCall();

        call->response_reader->Finish(&call->reply, &call->status, (void *)call);
    }
    void RequestCall(std::vector<std::shared_ptr<Struct>> request)
    {
        this->responses.resize(request.size());
        std::thread thread_ = std::thread(&QuantraClient::AsyncCompleteRpc, this, request.size());

        int request_tag = 0;
        for (auto it = request.begin(); it != request.end(); it++)
        {
            this->Call(*it, request_tag);
            request_tag += 1;
        }

        thread_.join();
    }
    std::shared_ptr<json_response> JSONRequest(std::string json)
    {
        auto builder = this->json_parser->PriceFixedRateBondRequestToFBS(json);

        this->json_responses.resize(1);
        std::thread thread_ = std::thread(&QuantraClient::AsyncCompleteRpc, this, 1);

        auto request_msg = builder->ReleaseMessage<Request>();

        AsyncClientCall *call = new AsyncClientCall;
        call->json = true;
        call->request_pos = 0;

        this->PrepareAsync();

        call->response_reader->StartCall();

        call->response_reader->Finish(&call->reply, &call->status, (void *)call);

        thread_.join();

        return this->json_responses[0];
    }

protected:
    struct AsyncClientCall
    {

        flatbuffers::grpc::Message<Response> reply;
        flatbuffers::grpc::Message<quantra::Error> error_details;
        grpc::ClientContext context;
        grpc::Status status;
        int request_pos;
        std::unique_ptr<grpc::ClientAsyncResponseReader<flatbuffers::grpc::Message<Response>>> response_reader;
        bool json = false;
    };
};

class PriceFixedRateBondData : public QuantraCall<quantra::PriceFixedRateBondRequest, structs::PriceFixedRateBondRequest, PriceFixedRateBondResponse>
{
    void PrepareAsync(std::unique_ptr<grpc::ClientAsyncResponseReader<flatbuffers::grpc::Message<Response>>> response_reader, std::shared_ptr<quantra::QuantraServer::Stub> stub_)
    {
        //std::unique_ptr< ::grpc::ClientAsyncResponseReader< flatbuffers::grpc::Message<PriceFixedRateBondResponse>>> PrepareAsyncPriceFixedRateBond(::grpc::ClientContext* context, const flatbuffers::grpc::Message<PriceFixedRateBondRequest>& request, ::grpc::CompletionQueue* cq) {
        response_reader =
            stub_->PrepareAsyncPriceFixedRateBond(&call->context, request_msg, &cq_);
    }
};