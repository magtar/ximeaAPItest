cmake_minimum_required(VERSION 3.0)
set(OpenCV_STATIC ON)


set(source ./xiApiPlusOcv.cpp ./xiApiPlusOcv.hpp)
add_library(xiApiPlusOcv ${source})
find_library(M3 m3api)
target_link_libraries(xiApiPlusOcv ${M3})
