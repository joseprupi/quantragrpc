project(quantra)

set(FLATBUFFERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/flatbuffers/fbs)
#set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/flatbuffers/fbs/*.h ${CMAKE_CURRENT_SOURCE_DIR}/grpc/*.h)

# add_subdirectory(${FLATBUFFERS_DIR}
#                  ${CMAKE_CURRENT_BINARY_DIR}/flatbuffers-build
#                  EXCLUDE_FROM_ALL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/grpc/
                    ${CMAKE_CURRENT_SOURCE_DIR}/flatbuffers/fbs)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/grpc)
LINK_DIRECTORIES(/root/grpc/install/lib/)
add_executable(client ./client/client.cpp)
TARGET_LINK_LIBRARIES(client gpr grpc grpc++ quantra_grpc)
#target_link_libraries(client PRIVATE flatbuffers)