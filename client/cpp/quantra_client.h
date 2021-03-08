#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <chrono>

#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>
#include <thread>

#include "quantra_to_fbs.h"
#include "fbs_to_quantra.h"
#include "quantraserver.grpc.fb.h"
#include "responses_generated.h"

class QuantraClient
{
public:
    explicit QuantraClient(std::string addr);

    void PriceFixedRateBondRequestCall(structs::PriceFixedRateBondRequest &request, int request_tag);
    void PriceFixedRateBondRequest(std::vector<structs::PriceFixedRateBondRequest> request);
    void AsyncCompleteRpc(int request_size);
    std::vector<structs::NPVResponse> responses;

private:
    struct AsyncClientCall
    {

        flatbuffers::grpc::Message<quantra::NPVResponse> reply;
        flatbuffers::grpc::Message<quantra::Error> error_details;
        grpc::ClientContext context;
        grpc::Status status;
        int request_pos;
        std::unique_ptr<grpc::ClientAsyncResponseReader<flatbuffers::grpc::Message<quantra::NPVResponse>>> response_reader;
    };

    std::unique_ptr<quantra::QuantraServer::Stub> stub_;
    grpc::CompletionQueue cq_;
};