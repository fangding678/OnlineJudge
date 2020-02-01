cmake_minimum_required(VERSION 3.7)

project(leetcode)
#
#set(CMAKE_CXX_STANDARD 11)

set(CMAKE_VERBOSE_MAKEFILE on)  # off

set(BASE_CXX_FLAGS "-std=c++11 -g -O3 -Wall")
set(CMAKE_CXX_FLAGS "${BASE_CXX_FLAGS}")


set(SOURCE_FILES main.cc)
add_executable(main ${SOURCE_FILES})

aux_source_directory(algorithm srcs)



#message(STATUS "link_libs:${link_libs}")
#
#function (add_program arg)
#    list(LENGTH ARGV  argv_len)
#    if (NOT (${argv_len} STREQUAL "1"))
#        message(FATAL_ERROR "argument number should be equals to 1")
#    endif()
#
#    set(prog_name ${ARGV0})
#    message(STATUS "exec_name: ${prog_name}, src_name: ${prog_name}.cc")
#    add_executable(${prog_name} "${prog_name}.cc")
##    target_link_libraries(${prog_name} ${link_libs})
#endfunction()
#
#
#add_program("main")


