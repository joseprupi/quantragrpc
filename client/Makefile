CXXFLAGS ?= -I/root/grpc/include/ -I/root/quantra/flatbuffers/fbs -I/root/quantra/parser -I/root/quantra/common -I/root/quantra/request -I/root/quantra/grpc
LDFLAGS ?= -L/root/grpc/install/lib/

.PHONY: all
all: client

client: 
	g++ -std=c++11 -O2 -g $(CXXFLAGS) $(LDFLAGS) -Wno-return-type -lgpr -lgrpc -lgrpc++ -lQuantLib client.cpp ../grpc/quantraserver.grpc.fb.cc -o $@