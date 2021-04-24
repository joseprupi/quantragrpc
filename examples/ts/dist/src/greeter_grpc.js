"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
// Generated GRPC code for FlatBuffers TS *** DO NOT EDIT ***
var flatbuffers_1 = require("flatbuffers");
var hello_reply_1 = require("./models/hello-reply");
var hello_request_1 = require("./models/hello-request");
var grpc = require('grpc');
function serialize_models_HelloReply(buffer_args) {
    if (!(buffer_args instanceof hello_reply_1.HelloReply)) {
        throw new Error('Expected argument of type HelloReply');
    }
    return buffer_args.serialize();
}
function deserialize_models_HelloReply(buffer) {
    return hello_reply_1.HelloReply.getRootAsHelloReply(new flatbuffers_1.flatbuffers.ByteBuffer(buffer));
}
function serialize_models_HelloRequest(buffer_args) {
    if (!(buffer_args instanceof hello_request_1.HelloRequest)) {
        throw new Error('Expected argument of type HelloRequest');
    }
    return buffer_args.serialize();
}
function deserialize_models_HelloRequest(buffer) {
    return hello_request_1.HelloRequest.getRootAsHelloRequest(new flatbuffers_1.flatbuffers.ByteBuffer(buffer));
}
var GreeterService = exports.GreeterService = {
    SayHello: {
        path: '/models.Greeter/SayHello',
        requestStream: false,
        responseStream: false,
        requestType: flatbuffers_1.flatbuffers.ByteBuffer,
        responseType: hello_reply_1.HelloReply,
        requestSerialize: serialize_models_HelloRequest,
        requestDeserialize: deserialize_models_HelloRequest,
        responseSerialize: serialize_models_HelloReply,
        responseDeserialize: deserialize_models_HelloReply,
    },
    SayManyHellos: {
        path: '/models.Greeter/SayManyHellos',
        requestStream: false,
        responseStream: true,
        requestType: flatbuffers_1.flatbuffers.ByteBuffer,
        responseType: hello_reply_1.HelloReply,
        requestSerialize: serialize_models_HelloRequest,
        requestDeserialize: deserialize_models_HelloRequest,
        responseSerialize: serialize_models_HelloReply,
        responseDeserialize: deserialize_models_HelloReply,
    },
};
exports.GreeterClient = grpc.makeGenericClientConstructor(GreeterService);
//# sourceMappingURL=greeter_grpc.js.map