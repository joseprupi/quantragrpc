import sys		
import grpc

sys.path.insert(0, '/root/tmp/flatbuffers/python/')

import flatbuffers
from models import HelloReply, HelloRequest, greeter_grpc_fb


def say_hello(stub, hello_request):
    reply = stub.SayHello(hello_request)
    r = HelloReply.HelloReply.GetRootAs(reply)
    print(r.Message())

def say_many_hellos(stub, hello_request):
    greetings = stub.SayManyHellos(hello_request)
    for greeting in greetings:
        r = HelloReply.HelloReply.GetRootAs(greeting)
        print(r.Message())

def main():
    port = 50055

    with grpc.insecure_channel('localhost:' + args.port) as channel:
        builder = flatbuffers.Builder()		
        ind = builder.CreateString(args.name)
        HelloRequest.HelloRequestStart(builder)
        HelloRequest.HelloRequestAddName(builder, ind)
        root = HelloRequest.HelloRequestEnd(builder)
        builder.Finish(root)
        output = bytes(builder.Output())
        stub = greeter_grpc_fb.GreeterStub(channel)
        say_hello(stub, output)
        say_many_hellos(stub, output)

main()