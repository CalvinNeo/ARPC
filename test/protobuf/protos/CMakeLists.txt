cmake_minimum_required(VERSION 3.5)
PROJECT(protos)

SET(CMAKE_CXX_COMPILER /usr/bin/g++-7 CACHE PATH "" FORCE)
SET(CMAKE_CXX_FLAGS_DEBUG "-w -Wno-unused-variable -Wno-unused-but-set-variable -DPOSIX -g -O0 -fpermissive -fPIC -std=c++1z")
find_package(Protobuf REQUIRED)
MESSAGE(STATUS "This is BINARY dir " ${proto_gen_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir "${proto_gen_SOURCE_DIR})
MESSAGE(STATUS "This is CMAKE SOURCE dir "${CMAKE_CURRENT_SOURCE_DIR})

FILE(GLOB protofiles "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")
PROTOBUF_GENERATE_CPP(PROTOSRCS PROTOHDRS ${protofiles})

MESSAGE(STATUS "SRC " ${PROTOSRCS} "HEAD" ${PROTOHDRS})
add_library(protos STATIC ${PROTOSRCS} ${PROTOHDRS}) 
target_link_libraries(protos protobuf) 
target_include_directories(protos PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
