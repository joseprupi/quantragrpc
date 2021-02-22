project(client)
 
#Bring the headers, such as Student.h into the project
include_directories("../grpc" "../parser" "../flatbuffers/fbs" "../request" "../common")
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "../grpc/*.cpp" "./*.cpp")
 
add_executable(client ${SOURCES})