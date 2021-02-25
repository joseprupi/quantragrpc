#include "quantraserver.grpc.fb.h"
#include "quantraserver_generated.h"

#include "fixed_rate_bond_pricing_request.h"
#include "responses_generated.h"

#include <grpcpp/grpcpp.h>

#include <iostream>
#include <memory>
#include <string>
#include <sstream>

class ServerImpl final
{
public:
    ~ServerImpl()
    {
        server_->Shutdown();
        // Always shutdown the completion queue after the server.
        cq_->Shutdown();
    }

    // There is no shutdown handling in this code.
    void Run(std::string port)
    {
        std::string server_address("127.0.0.1:" + port);

        grpc::ServerBuilder builder;
        // Listen on the given address without any authentication mechanism.
        builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
        // Register "service_" as the instance through which we'll communicate with
        // clients. In this case it corresponds to an *asynchronous* service.
        builder.RegisterService(&service_);
        // Get hold of the completion queue used for the asynchronous communication
        // with the gRPC runtime.
        cq_ = builder.AddCompletionQueue();
        // Finally assemble the server.
        server_ = builder.BuildAndStart();
        std::cout << "Server listening on " << server_address << std::endl;

        // Proceed to the server's main loop.
        HandleRpcs();
    }

private:
    // Class encompasing the state and logic needed to serve a request.
    class CallData
    {
    public:
        // Take in the "service" instance (in this case representing an asynchronous
        // server) and the completion queue "cq" used for asynchronous communication
        // with the gRPC runtime.
        CallData(QuantraServer::AsyncService *service, grpc::ServerCompletionQueue *cq)
            : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE)
        {
            // Invoke the serving logic right away.
            Proceed();
        }

        void Proceed()
        {
            if (status_ == CREATE)
            {
                status_ = PROCESS;
                service_->RequestBondPricing(&ctx_, &request_msg, &responder_, cq_, cq_,
                                             this);
            }
            else if (status_ == PROCESS)
            {
                //new CallData(service_, cq_);
                flatbuffers::grpc::MessageBuilder builder;
                FixedRateBondPricingRequest request;
                float npv = request.request(request_msg.GetRoot());

                auto offset = quantra::CreateNPVResponse(builder, npv);
                builder.Finish(offset);

                reply_ = builder.ReleaseMessage<quantra::NPVResponse>();
                assert(reply_.Verify());

                status_ = FINISH;
                responder_.Finish(reply_, grpc::Status::OK, this);
            }
            else
            {
                GPR_ASSERT(status_ == FINISH);
                // Once in the FINISH state, deallocate ourselves (CallData).
                delete this;
            }
        }

    private:
        QuantraServer::AsyncService *service_;
        grpc::ServerCompletionQueue *cq_;
        grpc::ServerContext ctx_;

        flatbuffers::grpc::Message<PriceFixedRateBondRequest> request_msg;
        flatbuffers::grpc::Message<NPVResponse> reply_;

        grpc::ServerAsyncResponseWriter<flatbuffers::grpc::Message<NPVResponse>> responder_;

        enum CallStatus
        {
            CREATE,
            PROCESS,
            FINISH
        };
        CallStatus status_; // The current serving state.
    };

    void HandleRpcs()
    {

        void *tag;
        bool ok;
        while (true)
        {
            // std::cout << "Received rpc" << std::endl
            //           << std::endl;

            new CallData(&service_, cq_.get());

            GPR_ASSERT(cq_->Next(&tag, &ok));
            GPR_ASSERT(ok);
            static_cast<CallData *>(tag)->Proceed();
        }
    }

    std::unique_ptr<grpc::ServerCompletionQueue> cq_;
    QuantraServer::AsyncService service_;
    std::unique_ptr<grpc::Server> server_;
};

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        std::string port(argv[1]);
        ServerImpl server;
        server.Run(port);
    }

    return 0;
}