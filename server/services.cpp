#include "services.h"

class CallData
{
public:
    virtual void Proceed() = 0;
};

template <class Message, class Request, class Response, class ResponseBuilder>
class CallDataGeneric : CallData
{
public:
    explicit CallDataGeneric(QuantraServer::AsyncService *service, grpc::ServerCompletionQueue *cq)
        : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE)
    {
    }

    void start()
    {
        Proceed();
    }

    void Proceed()
    {
        if (status_ == CREATE)
        {
            status_ = PROCESS;
            this->RequestCall();
        }
        else if (status_ == PROCESS)
        {
            std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder = std::make_shared<flatbuffers::grpc::MessageBuilder>();
            try
            {
                Request request;
                auto response = request.request(builder, request_msg.GetRoot());
                builder->Finish(response);

                reply_ = builder->ReleaseMessage<Response>();
                assert(reply_.Verify());

                status_ = FINISH;
                responder_.Finish(reply_, grpc::Status::OK, this);
            }
            catch (QuantLib::Error e)
            {

                std::string error_msg = "QuantLib error: ";
                error_msg.append(e.what());

                builder->Reset();
                ResponseBuilder empty_pricing(*builder);
                builder->Finish(empty_pricing.Finish());

                reply_ = builder->ReleaseMessage<Response>();
                assert(reply_.Verify());

                status_ = FINISH;
                auto status = grpc::Status(grpc::StatusCode::ABORTED, "QuantLib error", error_msg);
                responder_.Finish(reply_, status, this);
            }
            catch (QuantraError &e)
            {

                std::string error_msg = "Quantra error: ";
                error_msg.append(e.what());
                std::cout << "Quantra error:  " << error_msg << std::endl;

                builder->Reset();
                ResponseBuilder empty_pricing(*builder);
                builder->Finish(empty_pricing.Finish());

                reply_ = builder->ReleaseMessage<Response>();
                assert(reply_.Verify());

                status_ = FINISH;
                auto status = grpc::Status(grpc::StatusCode::ABORTED, "Quantra error", error_msg);
                responder_.Finish(reply_, status, this);
            }
            catch (std::exception e)
            {
                std::string error_msg = "Unknown error: ";
                error_msg.append(e.what());
                std::cout << "Unknown error:  " << error_msg << std::endl;

                builder->Reset();
                ResponseBuilder empty_pricing(*builder);
                builder->Finish(empty_pricing.Finish());

                reply_ = builder->ReleaseMessage<Response>();
                assert(reply_.Verify());

                status_ = FINISH;
                auto status = grpc::Status(grpc::StatusCode::ABORTED, "Unknown error", error_msg);
                responder_.Finish(reply_, status, this);
            }
            catch (...)
            {

                std::cout << "Unknown error exception:  " << std::endl;
            }
        }
        else
        {
            GPR_ASSERT(status_ == FINISH);
            delete this;
        }
    }

    virtual void RequestCall() = 0;

protected:
    QuantraServer::AsyncService *service_;
    grpc::ServerCompletionQueue *cq_;
    grpc::ServerContext ctx_;

    flatbuffers::grpc::Message<Message> request_msg;
    flatbuffers::grpc::Message<Response> reply_;

    grpc::ServerAsyncResponseWriter<flatbuffers::grpc::Message<Response>> responder_;

    enum CallStatus
    {
        CREATE,
        PROCESS,
        FINISH
    };
    CallStatus status_;
};

class PriceFixedRateBondData : public CallDataGeneric<quantra::PriceFixedRateBondRequest, FixedRateBondPricingRequest, PriceFixedRateBondResponse, PriceFixedRateBondResponseBuilder>
{
public:
    PriceFixedRateBondData(QuantraServer::AsyncService *service, grpc::ServerCompletionQueue *cq)
        : CallDataGeneric(service, cq)
    {
    }
    void RequestCall()
    {
        service_->RequestPriceFixedRateBond(&this->ctx_, &this->request_msg, &this->responder_, this->cq_, this->cq_, this);
    }
};

class PriceFloatingRateBondData : public CallDataGeneric<quantra::PriceFloatingRateBondRequest, FloatingRateBondPricingRequest, PriceFloatingRateBondResponse, PriceFloatingRateBondResponseBuilder>
{
public:
    PriceFloatingRateBondData(QuantraServer::AsyncService *service, grpc::ServerCompletionQueue *cq)
        : CallDataGeneric(service, cq)
    {
    }
    void RequestCall()
    {
        service_->RequestPriceFloatingRateBond(&this->ctx_, &this->request_msg, &this->responder_, this->cq_, this->cq_, this);
    }
};
