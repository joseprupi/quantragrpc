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
#include "responses_generated.h"

class QuantraClient
{
public:
    explicit QuantraClient(std::string addr, bool secured);

    std::shared_ptr<std::string> PriceFixedRateBondRequestJSON(std::string json);
    void PriceFixedRateBondRequestCallRaw(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, int request_tag);
    void PriceFixedRateBondRequestCall(std::shared_ptr<structs::PriceFixedRateBondRequest> request, int request_tag);
    void PriceFixedRateBondRequest(std::vector<std::shared_ptr<structs::PriceFixedRateBondRequest>> request);
    void AsyncCompleteRpc(int request_size);
    std::vector<std::shared_ptr<std::vector<std::shared_ptr<structs::PriceFixedRateBondValues>>>> responses;
    std::vector<std::shared_ptr<std::string>> json_responses;
    //std::vector<flatbuffers::grpc::Message<quantra::PriceFixedRateBondResponse>> raw_responses;

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
    //std::shared_ptr<flatbuffers::Parser> bond_parser = std::make_shared<flatbuffers::Parser>();
    //std::vector<std::string> paths = {FIXED_RATE_BOND_REQUEST_PATH};

    std::unique_ptr<quantra::QuantraServer::Stub> stub_;
    grpc::CompletionQueue cq_;
};