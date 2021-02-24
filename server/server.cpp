#include "quantraserver.grpc.fb.h"
#include "quantraserver_generated.h"

#include "fixed_rate_bond_pricing_request.h"
#include "responses_generated.h"

#include <grpcpp/grpcpp.h>

#include <iostream>
#include <memory>
#include <string>

class BondPricingServiceImpl final : public quantra::QuantraServer::Service
{

  virtual grpc::Status BondPricing(
      ::grpc::ServerContext *context,
      const flatbuffers::grpc::Message<PriceFixedRateBondRequest> *request_msg,
      flatbuffers::grpc::Message<NPVResponse> *response_msg) override
  {
    flatbuffers::grpc::MessageBuilder builder;

    FixedRateBondPricingRequest request;
    try
    {
      float npv = request.request(request_msg->GetRoot());

      auto hello_offset = quantra::CreateNPVResponse(builder, npv);
      builder.Finish(hello_offset);

      *response_msg = builder.ReleaseMessage<NPVResponse>();
      assert(response_msg->Verify());

      return grpc::Status::OK;
    }
    catch (const std::exception &e)
    {
      std::string s(e.what());
      return grpc::Status(grpc::StatusCode::UNKNOWN, s);
    }
  }
};

void RunServer()
{
  std::string server_address("0.0.0.0:50051");
  BondPricingServiceImpl service;

  grpc::ServerBuilder builder;

  grpc::ResourceQuota rq;
  rq.SetMaxThreads(100);
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
