cmake_minimum_required(VERSION 3.3)
project(convert2wav)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp patternGen.h encodingInterface.h patternGenTV.cpp patternGenCommon.cpp)
add_executable(convert2wav ${SOURCE_FILES} patternGen.h encodingInterface.h patternGenTV.cpp patternGenCommon.cpp)