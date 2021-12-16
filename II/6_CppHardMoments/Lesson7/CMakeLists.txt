cmake_minimum_required(VERSION 3.20)
project(test1)

set(CMAKE_CXX_STANDARD 17)

find_package(Protobuf REQUIRED)

#include_directories(${PROTOBUF_INCLUDE_DIRS})
#include_directories(${CMAKE_CURRENT_BINARY_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS Students.proto)

add_executable(test1 main.cpp Students.proto ${PROTO_SRCS} ${PROTO_HDRS} Interface.h)

target_link_libraries(test1 ${PROTOBUF_LIBRARY})
