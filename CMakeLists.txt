cmake_minimum_required (VERSION 3.10)

project (midas)

include_directories(include)

file(GLOB_RECURSE MIDAS_SRCS ./src *.cpp)

add_library(midas ${MIDAS_SRCS})

target_compile_features(midas PUBLIC cxx_std_20)