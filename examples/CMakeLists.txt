include_directories(
    ../grpc
    ../parser 
    ../flatbuffers/fbs 
    ../request 
    ../common
    ../client/cpp
    data)

file(GLOB ASYNC_SOURCES  
    ../parser/*.cpp 
    ../common/*.cpp 
    ../request/*.cpp  
    ./messages.cpp
    data/fixed_rate_bond_request_fbs.cpp
    ./async_client.cpp)

file(GLOB JSON_SOURCES  
    ../parser/*.cpp 
    ../common/*.cpp 
    ../request/*.cpp  
    ./messages.cpp
    data/fixed_rate_bond_request_fbs.cpp
    ./bond_request_to_json.cpp)

file(GLOB BOND_REQUEST_SORUCES
    ../parser/*.cpp
    ../common/*.cpp
    ../request/*.cpp  
    ./messages.cpp
    ./bond_request_example.cpp)

file(GLOB TEST_BOND
    ../parser/*.cpp
    ../common/*.cpp
    ../request/*.cpp  
    data/test.cpp
    ./test_bond.cpp)

find_package(Threads REQUIRED)
link_directories(/root/grpc/install/lib/)

add_executable(test_bond ${TEST_BOND})
add_executable(bond_request ${BOND_REQUEST_SORUCES})
#add_executable(async_client ${ASYNC_SOURCES})
#add_executable(bond_request_to_json ${JSON_SOURCES})

target_link_libraries(test_bond gpr grpc grpc++ flatbuffers quantra_grpc QuantLib Threads::Threads cpp_client)
target_link_libraries(bond_request gpr grpc grpc++ flatbuffers quantra_grpc QuantLib Threads::Threads cpp_client)
#target_link_libraries(async_client gpr grpc grpc++ flatbuffers quantra_grpc QuantLib Threads::Threads)
#target_link_libraries(bond_request_to_json gpr grpc grpc++ flatbuffers quantra_grpc QuantLib Threads::Threads)