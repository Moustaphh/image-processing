cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(Image)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

include_directories(src)

add_executable(Image src/main.cpp src/Image.cpp src/Image.h src/stb_image_write.h src/stb_image.h ../dither/FS/floyds.cpp src/rgb2gray.cpp)

target_include_directories(Image PRIVATE include)

set_property(TARGET Image PROPERTY CXX_STANDARD 17)