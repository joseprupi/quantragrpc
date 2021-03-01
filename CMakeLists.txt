project(quantra)
set(CMAKE_BUILD_TYPE Release)

set(FLATBUFFERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/flatbuffers/)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/grpc/
                    ${CMAKE_CURRENT_SOURCE_DIR}/flatbuffers/cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/flatbuffers)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/grpc)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/server)
