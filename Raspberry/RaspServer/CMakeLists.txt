project(RaspServer)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

include_directories(${RASP_MESSAGE_QUEUE_INCLUDE})

add_executable(${PROJECT_NAME} ${SRC_LIST})
if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-as-needed -std=c++11 -pthread")
endif()
target_link_libraries(${PROJECT_NAME} rt)
target_link_libraries(${PROJECT_NAME} RaspMessageQueue)
