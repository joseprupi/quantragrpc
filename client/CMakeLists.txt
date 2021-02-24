set(CMAKE_BUILD_TYPE Debug)
include_directories("../grpc" "../parser" "../flatbuffers/fbs" "../request" "../common")
 
file(GLOB SOURCES "../parser/*.cpp" "../common/*.cpp" "../request/*.cpp"  "./async_client.cpp")

find_package(Threads REQUIRED)
link_directories(/root/grpc/install/lib/)

add_executable(client ${SOURCES})
#add_executable(async_client ${SOURCES})
target_link_libraries(client gpr grpc grpc++ quantra_grpc QuantLib Threads::Threads)