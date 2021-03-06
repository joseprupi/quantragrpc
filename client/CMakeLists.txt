include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cpp
                    /root/quantra/flatbuffers/cpp
                    /root/quantra/grpc)

file(GLOB CPP_CLIENT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp)

find_package(Threads REQUIRED)
link_directories(/root/grpc/install/lib/)

add_library(cpp_client SHARED ${CPP_CLIENT_SOURCES})
target_link_libraries(cpp_client gpr grpc grpc++ flatbuffers quantra_grpc QuantLib Threads::Threads)