project(RaspMessageQueue)
cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SRC_LIST)
add_library(${PROJECT_NAME} STATIC ${SRC_LIST})

set(RASP_MESSAGE_QUEUE_INCLUDE ${PROJECT_SOURCE_DIR} PARENT_SCOPE)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-as-needed -std=c++11 -pthread")
endif()
target_link_libraries(${PROJECT_NAME} rt)

