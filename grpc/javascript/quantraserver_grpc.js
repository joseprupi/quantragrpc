// Generated GRPC code for FlatBuffers TS *** DO NOT EDIT ***
import { flatbuffers } from 'flatbuffers';
import { PriceFixedRateBondResponse as quantra_PriceFixedRateBondResponse } from './quantra/price-fixed-rate-bond-response';
import { PriceFixedRateBondRequest as quantra_PriceFixedRateBondRequest } from './quantra/price-fixed-rate-bond-request';

var grpc = require('grpc');

function serialize_quantra_PriceFixedRateBondResponse(buffer_args) {
  if (!(buffer_args instanceof quantra_PriceFixedRateBondResponse)) {
    throw new Error('Expected argument of type PriceFixedRateBondResponse');
  }
  return buffer_args.serialize();
}

function deserialize_quantra_PriceFixedRateBondResponse(buffer) {
  return quantra_PriceFixedRateBondResponse.getRootAsPriceFixedRateBondResponse(new flatbuffers.ByteBuffer(buffer))
}


function serialize_quantra_PriceFixedRateBondRequest(buffer_args) {
  if (!(buffer_args instanceof quantra_PriceFixedRateBondRequest)) {
    throw new Error('Expected argument of type PriceFixedRateBondRequest');
  }
  return buffer_args.serialize();
}

function deserialize_quantra_PriceFixedRateBondRequest(buffer) {
  return quantra_PriceFixedRateBondRequest.getRootAsPriceFixedRateBondRequest(new flatbuffers.ByteBuffer(buffer))
}

var QuantraServerService = exports.QuantraServerService = {
  PriceFixedRateBond: {
    path: '/quantra.QuantraServer/PriceFixedRateBond',
    requestStream: false,
    responseStream: false,
    requestType: flatbuffers.ByteBuffer,
    responseType: quantra_PriceFixedRateBondResponse,
    requestSerialize: serialize_quantra_PriceFixedRateBondRequest,
    requestDeserialize: deserialize_quantra_PriceFixedRateBondRequest,
    responseSerialize: serialize_quantra_PriceFixedRateBondResponse,
    responseDeserialize: deserialize_quantra_PriceFixedRateBondResponse,
  },
};
exports.QuantraServerClient = grpc.makeGenericClientConstructor(QuantraServerService);
