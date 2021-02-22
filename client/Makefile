CXXFLAGS ?= -I/root/grpc/include/ -I/root/quantra/flatbuffers/fbs -I/root/quantra/parser -I/root/quantra/common -I/root/quantra/request
LDFLAGS ?= -L/root/grpc/install/lib/

.PHONY: all
all: server

server: 
	g++ -std=c++11 -O2 $(CXXFLAGS) $(LDFLAGS) -Wno-return-type -lgpr -lgrpc -lgrpc++ -lQuantLib client.cpp -o $@