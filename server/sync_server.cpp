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
        cq_->Shutdown();
    }

    void Run(std::string port)
    {
        std::string server_address("127.0.0.1:" + port);

        grpc::ServerBuilder builder;
        builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
        builder.RegisterService(&service_);
        cq_ = builder.AddCompletionQueue();
        server_ = builder.BuildAndStart();
        std::cout << "Server listening on " << server_address << std::endl;

        HandleRpcs();
    }

private:
    class CallData
    {
    public:
        CallData(QuantraServer::AsyncService *service, grpc::ServerCompletionQueue *cq)
            : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE)
        {
            Proceed();
        }

        void Proceed()
        {
            if (status_ == CREATE)
            {
                status_ = PROCESS;
                service_->RequestPriceFixedRateBond(&ctx_, &request_msg, &responder_, cq_, cq_,
                                                    this);
            }
            else if (status_ == PROCESS)
            {
                std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder = std::make_shared<flatbuffers::grpc::MessageBuilder>();
                try
                {
                    FixedRateBondPricingRequest request;
                    auto response = request.request(builder, request_msg.GetRoot());
                    builder->Finish(response);

                    reply_ = builder->ReleaseMessage<quantra::PriceFixedRateBondResponse>();
                    assert(reply_.Verify());

                    status_ = FINISH;
                    responder_.Finish(reply_, grpc::Status::OK, this);
                }
                catch (QuantLib::Error e)
                {

                    std::string error_msg = "QuantLib error: ";
                    error_msg.append(e.what());

                    builder->Reset();
                    PriceFixedRateBondResponseBuilder empty_pricing(*builder);
                    builder->Finish(empty_pricing.Finish());

                    reply_ = builder->ReleaseMessage<quantra::PriceFixedRateBondResponse>();
                    assert(reply_.Verify());

                    status_ = FINISH;
                    auto status = grpc::Status(grpc::StatusCode::ABORTED, "QuantLib error", error_msg);
                    responder_.Finish(reply_, status, this);
                }
                catch (std::exception e)
                {
                    std::string error_msg = "Unknown error: ";
                    error_msg.append(e.what());

                    builder->Reset();
                    PriceFixedRateBondResponseBuilder empty_pricing(*builder);
                    builder->Finish(empty_pricing.Finish());

                    reply_ = builder->ReleaseMessage<quantra::PriceFixedRateBondResponse>();
                    assert(reply_.Verify());

                    status_ = FINISH;
                    auto status = grpc::Status(grpc::StatusCode::ABORTED, "Unknown error", error_msg);
                    responder_.Finish(reply_, status, this);
                }
            }
            else
            {
                GPR_ASSERT(status_ == FINISH);
                delete this;
            }
        }

    private:
        QuantraServer::AsyncService *service_;
        grpc::ServerCompletionQueue *cq_;
        grpc::ServerContext ctx_;

        flatbuffers::grpc::Message<PriceFixedRateBondRequest> request_msg;
        flatbuffers::grpc::Message<PriceFixedRateBondResponse> reply_;

        grpc::ServerAsyncResponseWriter<flatbuffers::grpc::Message<PriceFixedRateBondResponse>> responder_;

        enum CallStatus
        {
            CREATE,
            PROCESS,
            FINISH
        };
        CallStatus status_;
    };

    void HandleRpcs()
    {

        void *tag;
        bool ok;
        while (true)
        {
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
    else
    {
        ServerImpl server;
        server.Run("50051");
    }

    return 0;
}