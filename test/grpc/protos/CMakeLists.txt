cmake_minimum_required(VERSION 3.5)

PROJECT(protos)
SET(CMAKE_CXX_COMPILER /usr/bin/g++-7 CACHE PATH "" FORCE)
SET(CMAKE_CXX_FLAGS_DEBUG "-w -Wno-unused-variable -Wno-unused-but-set-variable -DPOSIX -g -O0 -fpermissive -fPIC -std=c++1z")

find_package(Protobuf REQUIRED)
include(cmake_grpc_cpp.cmake)

FILE(GLOB protofiles "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")

PROTOBUF_GENERATE_CPP(CLISRC CLIH ${protofiles})
MESSAGE(STATUS "CLI SRC " ${CLISRC} ", CLI HEAD " ${CLIH})
add_library(proto_cli STATIC ${CLISRC} ${CLIH}) 
target_link_libraries(proto_cli protobuf grpc++ grpc) 
target_include_directories(proto_cli PUBLIC ${CMAKE_CURRENT_BINARY_DIR})


PROTOBUF_GENERATE_GRPC_CPP(SVRSRC SVRH ${protofiles})
MESSAGE(STATUS "SVR SRC " ${SVRSRC} ", SVR HEAD " ${SVRH})
add_library(proto_svr STATIC ${SVRSRC} ${SVRH} ${CLIH}) 
target_link_libraries(proto_svr protobuf grpc++ grpc) 
target_include_directories(proto_svr PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
