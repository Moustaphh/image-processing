cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(Floyd_Steinberg)

find_package(OpenCV REQUIRED)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OPENCV_CXX_FLAGS}")
add_executable(Floyd_Steinberg src/floyd_steinberg.cpp)

target_include_directories(Floyd_Steinberg PRIVATE include)
target_link_libraries(Floyd_Steinberg "${OpenCV_LIBS}")

set_property(TARGET Floyd_Steinberg PROPERTY CXX_STANDARD 14)
