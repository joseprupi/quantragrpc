#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <chrono>

#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>
#include <thread>

#include "data/fixed_rate_bond_request_fbs.h"

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

class QuantraClient
{
public:
    explicit QuantraClient(std::shared_ptr<grpc::Channel> channel)
        : stub_(quantra::QuantraServer::NewStub(channel)) {}

    void PriceBond(quantra::PriceFixedRateBondRequest *request)
    {
        std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder = std::make_shared<flatbuffers::grpc::MessageBuilder>();

        grpc_slice = grpc_slice_new 

        auto p = request->GetPointer();
        flatbuffers::grpc::SliceAllocator slice_allocator_;
        grpc_slice slice = slice_allocator_.get_slice(buf_data, buf_size);
        // Extract a subslice of the existing slice (increment refcount)
        grpc_slice subslice = grpc_slice_sub(slice, begin, end);
        // Wrap the subslice in a `Message<T>`, but don't increment refcount
        flatbuffers::grpc::Message<quantra::PriceFixedRateBondRequest> msg(subslice, false);

        AsyncClientCall *call = new AsyncClientCall;

        call->response_reader =
            stub_->PrepareAsyncBondPricing(&call->context, msg, &cq_);

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

int PriceFixedRateBondRequest(std::vector<quantra::PriceFixedRateBondRequest *> requests)
{

    QuantraClient quantra_client(grpc::CreateChannel(
        "localhost:50051", grpc::InsecureChannelCredentials()));

    std::thread thread_ = std::thread(&QuantraClient::AsyncCompleteRpc, &quantra_client, n);

    for (auto it = requests.begin(); it != requests.end(); it++)
    {
    }

    thread_.join();

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    return 0;
}