// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: quantraserver

#include "quantraserver_generated.h"
#include "quantraserver.grpc.fb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace quantra
{

  static const char *QuantraServer_method_names[] = {
      "/quantra.QuantraServer/BondPricing",
  };

  std::unique_ptr<QuantraServer::Stub> QuantraServer::NewStub(const std::shared_ptr<::grpc::ChannelInterface> &channel, const ::grpc::StubOptions &options)
  {
    std::unique_ptr<QuantraServer::Stub> stub(new QuantraServer::Stub(channel));
    return stub;
  }

  QuantraServer::Stub::Stub(const std::shared_ptr<::grpc::ChannelInterface> &channel)
      : channel_(channel), rpcmethod_BondPricing_(QuantraServer_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {
  }

  ::grpc::Status QuantraServer::Stub::BondPricing(::grpc::ClientContext *context, const flatbuffers::grpc::Message<BondPricingRequest> &request, flatbuffers::grpc::Message<BondPricingReply> *response)
  {
    return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_BondPricing_, context, request, response);
  }

  ::grpc::ClientAsyncResponseReader<flatbuffers::grpc::Message<BondPricingReply>> *QuantraServer::Stub::AsyncBondPricingRaw(::grpc::ClientContext *context, const flatbuffers::grpc::Message<BondPricingRequest> &request, ::grpc::CompletionQueue *cq)
  {
    return ::grpc::internal::ClientAsyncResponseReaderFactory<flatbuffers::grpc::Message<BondPricingReply>>::Create(channel_.get(), cq, rpcmethod_BondPricing_, context, request, true);
  }

  ::grpc::ClientAsyncResponseReader<flatbuffers::grpc::Message<BondPricingReply>> *QuantraServer::Stub::PrepareAsyncBondPricingRaw(::grpc::ClientContext *context, const flatbuffers::grpc::Message<BondPricingRequest> &request, ::grpc::CompletionQueue *cq)
  {
    return ::grpc::internal::ClientAsyncResponseReaderFactory<flatbuffers::grpc::Message<BondPricingReply>>::Create(channel_.get(), cq, rpcmethod_BondPricing_, context, request, false);
  }

  QuantraServer::Service::Service()
  {
    AddMethod(new ::grpc::internal::RpcServiceMethod(
        QuantraServer_method_names[0],
        ::grpc::internal::RpcMethod::NORMAL_RPC,
        new ::grpc::internal::RpcMethodHandler<QuantraServer::Service, flatbuffers::grpc::Message<BondPricingRequest>, flatbuffers::grpc::Message<BondPricingReply>>(
            std::mem_fn(&QuantraServer::Service::BondPricing), this)));
  }

  QuantraServer::Service::~Service()
  {
  }

  ::grpc::Status QuantraServer::Service::BondPricing(::grpc::ServerContext *context, const flatbuffers::grpc::Message<BondPricingRequest> *request, flatbuffers::grpc::Message<BondPricingReply> *response)
  {
    (void)context;
    (void)request;
    (void)response;
    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
  }

} // namespace quantra
