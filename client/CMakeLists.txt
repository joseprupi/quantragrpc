set(CMAKE_BUILD_TYPE Debug)
include_directories("../grpc" "../parser" "../flatbuffers/fbs" "../request" "../common")
 
file(GLOB SYNC_SOURCES " ../parser/*.cpp" "
                    ../common/*.cpp" "
                    ../request/*.cpp"  
                    "./sync_client.cpp")

file(GLOB ASYNC_SOURCES " ../parser/*.cpp" "
                    ../common/*.cpp" "
                    ../request/*.cpp"  
                    "./async_client.cpp")

find_package(Threads REQUIRED)
link_directories(/root/grpc/install/lib/)

add_executable(sync_client ${SYNC_SOURCES})
add_executable(async_client ${ASYNC_SOURCES})
target_link_libraries(sync_client gpr grpc grpc++ quantra_grpc QuantLib Threads::Threads)
target_link_libraries(async_client gpr grpc grpc++ quantra_grpc QuantLib Threads::Threads)