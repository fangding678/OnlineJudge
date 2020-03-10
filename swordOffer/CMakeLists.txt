cmake_minimum_required(VERSION 3.7)

project(swordOffer)
#
#set(CMAKE_CXX_STANDARD 11)

set(CMAKE_VERBOSE_MAKEFILE on)  # off

set(BASE_CXX_FLAGS "-std=c++11 -g -O3 -Wall")
set(CMAKE_CXX_FLAGS "${BASE_CXX_FLAGS}")


set(SOURCE_FILES main.cc)
add_executable(main ${SOURCE_FILES})

aux_source_directory(algo srcs)


