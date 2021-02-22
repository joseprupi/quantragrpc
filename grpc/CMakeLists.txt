set(grpc_src
    quantraserver_generated.h
    quantraserver.grpc.fb.cc
    quantraserver.grpc.fb.h
)

include_directories(/root/grpc/include/)

add_library(quantra_grpc ${grpc_src})