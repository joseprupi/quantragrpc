set(CMAKE_BUILD_TYPE Debug)
include_directories("../grpc" 
                    "../parser" 
                    "../flatbuffers/fbs" 
                    "../request" 
                    "../common")
 
file(GLOB SYNC_SOURCES   "../parser/*.cpp" 
                    "../common/*.cpp" 
                    "../request/*.cpp"  
                    "./sync_server.cpp")

file(GLOB ASYNC_SOURCES   "../parser/*.cpp" 
                    "../common/*.cpp" 
                    "../request/*.cpp"  
                    "./sync_server.cpp")

link_directories(/root/grpc/install/lib/)
add_executable(sync_server ${SYNC_SOURCES})
add_executable(async_server ${ASYNC_SOURCES})
target_link_libraries(sync_server gpr grpc grpc++ quantra_grpc QuantLib)
target_link_libraries(async_server gpr grpc grpc++ quantra_grpc QuantLib)