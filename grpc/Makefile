CXXFLAGS ?= -I/root/grpc/include/ -I/root/quantra/flatbuffers/fbs -I/root/quantra/parser -I/root/quantra/common
LDFLAGS ?= -L/root/grpc/install/lib/

.PHONY: all
all: server

server_generated.h: server.fbs
	flatc --grpc --cpp $<

server: server.cpp quantraserver.grpc.fb.cc quantraserver_generated.h quantraserver.grpc.fb.h
	g++ -std=c++11 -O2 $(CXXFLAGS) $(LDFLAGS) -Wno-return-type -lgpr -lgrpc -lgrpc++ -lQuantLib server.cpp quantraserver.grpc.fb.cc ../parser/term_structure_parser.cpp -o $@