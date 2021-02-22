project(quantra)
set(CMAKE_BUILD_TYPE Debug)

set(FLATBUFFERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/flatbuffers/fbs)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/grpc/
                    ${CMAKE_CURRENT_SOURCE_DIR}/flatbuffers/fbs)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/grpc)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/client)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/server)