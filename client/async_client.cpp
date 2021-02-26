#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>
#include <thread>

#include "quantraserver.grpc.fb.h"
#include "quantraserver_generated.h"
#include "responses_generated.h"

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

class QuantraClient
{
private:
    int n_servers;

public:
    explicit QuantraClient(std::shared_ptr<grpc::Channel> channel)
        : stub_(quantra::QuantraServer::NewStub(channel)) {}

    void PriceBond(flatbuffers::grpc::Message<quantra::PriceFixedRateBondRequest> request_msg)
    {
        AsyncClientCall *call = new AsyncClientCall;

        call->response_reader = stub_->PrepareAsyncBondPricing(&call->context, request_msg, &cq_);
        call->response_reader->StartCall();
        call->response_reader->Finish(&call->reply, &call->status, (void *)call);
    }

    void AsyncCompleteRpc(int n)
    {
        void *got_tag;
        bool ok = false;

        int req_count = 0;
        std::cout << "Start loop" << std::endl;
        while (cq_.Next(&got_tag, &ok))
        {
            AsyncClientCall *call = static_cast<AsyncClientCall *>(got_tag);

            GPR_ASSERT(ok);

            if (call->status.ok())
            {
                const quantra::NPVResponse *response = call->reply.GetRoot();
                auto npv = response->npv();
            }
            else
                std::cout << "RPC failed" << call->status.error_code() << std::endl;

            delete call;

            req_count += 1;

            if (req_count == n)
                break;
        }
    }

private:
    struct AsyncClientCall
    {

        flatbuffers::grpc::Message<quantra::NPVResponse> reply;
        grpc::ClientContext context;
        grpc::Status status;

        std::unique_ptr<grpc::ClientAsyncResponseReader<flatbuffers::grpc::Message<quantra::NPVResponse>>> response_reader;
    };

    std::unique_ptr<quantra::QuantraServer::Stub> stub_;
    grpc::CompletionQueue cq_;
};

int main(int argc, char **argv)
{

    QuantraClient quantra_client(grpc::CreateChannel(
        "localhost:50051", grpc::InsecureChannelCredentials()));

    int n = 1;

    if (argc > 1)
    {
        std::istringstream iss(argv[1]);
        iss >> n;
    }

    std::thread thread_ = std::thread(&QuantraClient::AsyncCompleteRpc, &quantra_client, n);

    for (int i = 0; i < n; i++)
    {
        quantra_client.PriceBond();
    }

    thread_.join();
    std::cout << "Finish" << std::endl;
    return 0;
}