set(CMAKE_BUILD_TYPE Debug)
include_directories("../grpc" "../parser" "../flatbuffers/fbs" "../request" "../common")
 
file(GLOB SOURCES "../parser/*.cpp" "../common/*.cpp" "../request/*.cpp"  "./*.cpp")

link_directories(/root/grpc/install/lib/)
add_executable(client ${SOURCES})
target_link_libraries(client gpr grpc grpc++ quantra_grpc QuantLib)