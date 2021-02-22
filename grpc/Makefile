CXXFLAGS ?= -I/root/grpc/include/ -I/root/quantra/flatbuffers/fbs -I/root/quantra/parser -I/root/quantra/common -I/root/quantra/request 
LDFLAGS ?= -L/root/grpc/install/lib/

.PHONY: all
all: server

server_generated.h: server.fbs
	flatc --grpc --cpp $<

server: 
	g++ -std=c++11 -O2 $(CXXFLAGS) $(LDFLAGS) -Wno-return-type -lgpr -lgrpc -lgrpc++ -lQuantLib server.cpp quantraserver.grpc.fb.cc ../request/fixed_rate_bond_pricing_request.cpp ../parser/term_structure_point_parser.cpp ../parser/term_structure_parser.cpp ../parser/fixed_rate_bond_parser.cpp ../parser/common_parser.cpp ../common/common.cpp ../common/enums.cpp  -o $@