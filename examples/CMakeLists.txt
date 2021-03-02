#set(CMAKE_BUILD_TYPE Debug)
include_directories("../grpc" 
                    "../parser" 
                    "../flatbuffers/fbs" 
                    "../request" 
                    "../common"
                    "data")
 
# file(GLOB SYNC_SOURCES " ../parser/*.cpp" "
#                     ../common/*.cpp" "
#                     ../request/*.cpp"  
#                     "./sync_client.cpp")

file(GLOB ASYNC_SOURCES " ../parser/*.cpp" "
                    ../common/*.cpp" "
                    ../request/*.cpp"  
                    "./messages.cpp"
                    "data/fixed_rate_bond_request_fbs.cpp"
                    "./async_client.cpp")

file(GLOB JSON_SOURCES " ../parser/*.cpp" "
                    ../common/*.cpp" "
                    ../request/*.cpp"  
                    "./messages.cpp"
                    "data/fixed_rate_bond_request_fbs.cpp"
                    "./bond_request_to_json.cpp")

find_package(Threads REQUIRED)
link_directories(/root/grpc/install/lib/)

#add_executable(sync_client ${SYNC_SOURCES})
add_executable(async_client ${ASYNC_SOURCES})
add_executable(bond_request_to_json ${JSON_SOURCES})

#target_link_libraries(sync_client gpr grpc grpc++ flatbuffers quantra_grpc QuantLib Threads::Threads)
target_link_libraries(async_client gpr grpc grpc++ flatbuffers quantra_grpc QuantLib Threads::Threads)
target_link_libraries(bond_request_to_json gpr grpc grpc++ flatbuffers quantra_grpc QuantLib Threads::Threads)