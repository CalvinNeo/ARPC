cmake_minimum_required(VERSION 3.5)

PROJECT(test_grpc)

SET(CMAKE_CXX_COMPILER /usr/bin/g++-7 CACHE PATH "" FORCE)
SET(CMAKE_CXX_FLAGS_DEBUG "-w -Wno-unused-variable -Wno-unused-but-set-variable -DPOSIX -g -O0 -fpermissive -fPIC -std=c++1z")

add_subdirectory(protos)
add_executable(greeter_server greeter_server.cpp) 
add_executable(greeter_client greeter_client.cpp) 
target_link_libraries(greeter_server proto_svr proto_cli)
target_link_libraries(greeter_client proto_svr proto_cli)
target_include_directories(greeter_server PUBLIC ${CMAKE_CURRENT_BINARY_DIR} protos)
target_include_directories(greeter_client PUBLIC ${CMAKE_CURRENT_BINARY_DIR} protos)
