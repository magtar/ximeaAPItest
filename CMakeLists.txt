cmake_minimum_required(VERSION 3.0)
project(WFS)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} ./lib)
subdirs(lib)

add_executable(Viewer main.cpp)

target_link_libraries(Viewer ${OpenCV_LIBS} xiApiPlusOcv)