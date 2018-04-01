cmake_minimum_required(VERSION 3.5)

PROJECT(test_grpc)

SET(CMAKE_CXX_COMPILER /usr/bin/g++-7 CACHE PATH "" FORCE)
SET(CMAKE_CXX_FLAGS_DEBUG "-w -Wno-unused-variable -Wno-unused-but-set-variable -DPOSIX -g -O0 -fpermissive -fPIC -std=c++1z")

add_subdirectory(protos)
add_executable(test_grpc protobuf_helloworld.cpp) 
target_link_libraries(test_grpc protos)