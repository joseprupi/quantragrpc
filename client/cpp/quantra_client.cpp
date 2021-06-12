#include "quantra_client.h"

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

#include <string>
#include <fstream>
#include <streambuf>

QuantraClient::QuantraClient(std::string addr, bool secured)
{
    grpc::ChannelArguments ch_args;
    ch_args.SetMaxReceiveMessageSize(INT_MAX);

    std::shared_ptr<grpc::ChannelCredentials> channel_creds;

    if (secured)
    {
        grpc::SslCredentialsOptions ssl_opts;
        std::ifstream t("cert.pem");
        std::string str((std::istreambuf_iterator<char>(t)),
                        std::istreambuf_iterator<char>());
        ssl_opts.pem_root_certs = str;

        channel_creds = grpc::SslCredentials(ssl_opts);
    }
    else
    {
        channel_creds = grpc::InsecureChannelCredentials();
    }

    std::shared_ptr<grpc::Channel> channel = grpc::CreateCustomChannel(
        addr, channel_creds, ch_args);

    this->stub_ = std::make_unique<quantra::QuantraServer::Stub>(channel);
}

std::shared_ptr<std::string> QuantraClient::PriceFixedRateBondRequestJSON(std::string json)
{
    auto builder = this->json_parser->PriceFixedRateBondRequestToFBS(json);
    this->PriceFixedRateBondRequestCallRaw(builder, 0);
    //return this->json_parser->PriceFixedRateBondResponseToJSON(this->raw_responses[0].get());
    //std::string s;
    return this->json_responses[0];
}

void QuantraClient::PriceFixedRateBondRequestCallRaw(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, int request_tag)
{

    //this->responses.resize(1);
    this->json_responses.resize(1);
    std::thread thread_ = std::thread(&QuantraClient::AsyncCompleteRpc, this, 1);

    auto request_msg = builder->ReleaseMessage<quantra::PriceFixedRateBondRequest>();

    AsyncClientCall *call = new AsyncClientCall;
    call->json = true;
    call->request_pos = request_tag;

    call->response_reader =
        stub_->PrepareAsyncPriceFixedRateBond(&call->context, request_msg, &cq_);

    call->response_reader->StartCall();

    call->response_reader->Finish(&call->reply, &call->status, (void *)call);

    thread_.join();
}

void QuantraClient::PriceFixedRateBondRequestCall(std::shared_ptr<structs::PriceFixedRateBondRequest> request, int request_tag)
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

void QuantraClient::PriceFixedRateBondRequest(std::vector<std::shared_ptr<structs::PriceFixedRateBondRequest>> request)
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
            int position = call->request_pos;
            if (call->json)
            {
                this->json_responses[position] = this->json_parser->PriceFixedRateBondResponseToJSON(call->reply.data());
                std::cout << this->json_responses[position].get();
            }
            else
            {

                auto quantra_response = price_fixed_rate_bond_response_to_quantra(response);
                this->responses.at(position) = quantra_response;
            }
            //std::shared_ptr<const uint8_t> data = std::make_shared<const uint8_t>(call->reply.data());
            //std::shared_ptr<const uint8_t> data(new uint8_t[call->reply.size()], std::default_delete<const uint8_t[]>());

            //this->raw_responses.at(position) = std::make_shared<flatbuffers::grpc::Message<quantra::PriceFixedRateBondResponse>>(call->reply);
            //this->raw_responses.at(position) = call->reply;

            //std::string s = this->json_parser->PriceFixedRateBondResponseToJSON(call->reply.data());
            //std::cout << s;
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