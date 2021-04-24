"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
// Generated GRPC code for FlatBuffers TS *** DO NOT EDIT ***
var flatbuffers_1 = require("flatbuffers");
var price_fixed_rate_bond_response_1 = require("./quantra/price-fixed-rate-bond-response");
var price_fixed_rate_bond_request_1 = require("./quantra/price-fixed-rate-bond-request");
var grpc = require('grpc');
function serialize_quantra_PriceFixedRateBondResponse(buffer_args) {
    if (!(buffer_args instanceof price_fixed_rate_bond_response_1.PriceFixedRateBondResponse)) {
        throw new Error('Expected argument of type PriceFixedRateBondResponse');
    }
    return buffer_args.serialize();
}
function deserialize_quantra_PriceFixedRateBondResponse(buffer) {
    return price_fixed_rate_bond_response_1.PriceFixedRateBondResponse.getRootAsPriceFixedRateBondResponse(new flatbuffers_1.flatbuffers.ByteBuffer(buffer));
}
function serialize_quantra_PriceFixedRateBondRequest(buffer_args) {
    if (!(buffer_args instanceof price_fixed_rate_bond_request_1.PriceFixedRateBondRequest)) {
        throw new Error('Expected argument of type PriceFixedRateBondRequest');
    }
    return buffer_args.serialize();
}
function deserialize_quantra_PriceFixedRateBondRequest(buffer) {
    return price_fixed_rate_bond_request_1.PriceFixedRateBondRequest.getRootAsPriceFixedRateBondRequest(new flatbuffers_1.flatbuffers.ByteBuffer(buffer));
}
var QuantraServerService = exports.QuantraServerService = {
    PriceFixedRateBond: {
        path: '/quantra.QuantraServer/PriceFixedRateBond',
        requestStream: false,
        responseStream: false,
        requestType: flatbuffers_1.flatbuffers.ByteBuffer,
        responseType: price_fixed_rate_bond_response_1.PriceFixedRateBondResponse,
        requestSerialize: serialize_quantra_PriceFixedRateBondRequest,
        requestDeserialize: deserialize_quantra_PriceFixedRateBondRequest,
        responseSerialize: serialize_quantra_PriceFixedRateBondResponse,
        responseDeserialize: deserialize_quantra_PriceFixedRateBondResponse,
    },
};
exports.QuantraServerClient = grpc.makeGenericClientConstructor(QuantraServerService);
//# sourceMappingURL=quantraserver_grpc.js.map