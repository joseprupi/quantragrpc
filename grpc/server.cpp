#include "quantraserver.grpc.fb.h"
#include "quantraserver_generated.h"

#include "term_structure_parser.h"

#include <grpcpp/grpcpp.h>

#include <iostream>
#include <memory>
#include <string>

class BondPricingServiceImpl final : public quantra::QuantraServer::Service
{
  virtual grpc::Status BondPricing(
      ::grpc::ServerContext *context,
      const flatbuffers::grpc::Message<quantra::PriceFixedRateBond> *request_msg,
      flatbuffers::grpc::Message<quantra::BondPricingReply> *response_msg) override
  {
    flatbuffers::grpc::MessageBuilder mb_;

    const quantra::PriceFixedRateBond *request = request_msg->GetRoot();

    auto pricing = request->pricing();
    auto fixed_rate_bond = request->fixed_rate_bond();
    auto curve = request->curves()->Get(0);

    TermStructureParser tsparser = TermStructureParser();
    tsparser.parse(curve);
    //const quantra::BondPricingRequest *request = request_msg->GetRoot();

    // const std::string &name = request->name()->str();

    // auto msg_offset = mb_.CreateString("Hello, " + name);
    // auto hello_offset = quantra::CreateBondPricingReply(mb_, msg_offset);
    // mb_.Finish(hello_offset);

    // *response_msg = mb_.ReleaseMessage<quantra::BondPricingReply>();
    // assert(response_msg->Verify());

    return grpc::Status::OK;
  }

  flatbuffers::grpc::MessageBuilder mb_;
};

void RunServer()
{
  std::string server_address("0.0.0.0:50051");
  BondPricingServiceImpl service;

  grpc::ServerBuilder builder;

  grpc::ResourceQuota rq;
  rq.SetMaxThreads(1);
  builder.SetResourceQuota(rq);

  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cerr << "Server listening on " << server_address << std::endl;

  server->Wait();
}

int main(int argc, const char *argv[])
{
  RunServer();
  return 0;
}
