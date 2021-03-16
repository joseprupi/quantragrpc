include_directories(
    ../grpc
    ../parser 
    ../flatbuffers/fbs 
    ../request 
    ../common
    ../client/cpp
    ../examples)

file(GLOB TEST  
    ./test.cpp)

file(GLOB TEST_QUANTRA
    ./test_quantra.cpp)

file(GLOB TEST_QUANTLIB  
    ./test_quantlib.cpp)

file(GLOB TEST2  
    ./test2.cpp)

link_directories(/root/grpc/install/lib/)

add_executable(test ${TEST})
add_executable(test2 ${TEST2})
add_executable(test_quantra ${TEST_QUANTRA})
add_executable(test_quantlib ${TEST_QUANTLIB})

target_link_libraries(test gpr grpc grpc++ flatbuffers quantra_grpc QuantLib cpp_client)
target_link_libraries(test2 gpr grpc grpc++ flatbuffers quantra_grpc QuantLib cpp_client)
target_link_libraries(test_quantra gpr grpc grpc++ flatbuffers quantra_grpc QuantLib cpp_client)
target_link_libraries(test_quantlib gpr grpc grpc++ flatbuffers quantra_grpc QuantLib cpp_client)