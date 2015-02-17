project(RaspOpenCV)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

include_directories(${RASP_MESSAGE_QUEUE_INCLUDE})

add_executable(${PROJECT_NAME} ${SRC_LIST})
if(UNIX)
    SET( ENV{LD_LIBRARY_PATH} /usr/lib/x86_64-linux-gnu/libv4l/v4l1compat.so)
endif()

target_link_libraries(${PROJECT_NAME} RaspMessageQueue)
target_link_libraries(${PROJECT_NAME} opencv_core)
target_link_libraries(${PROJECT_NAME} opencv_imgproc)
target_link_libraries(${PROJECT_NAME} opencv_highgui)
target_link_libraries(${PROJECT_NAME} opencv_objdetect)
target_link_libraries(${PROJECT_NAME} pthread)
