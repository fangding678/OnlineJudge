cmake_minimum_required(VERSION 3.13)
project(OnlineJudge)

set(CMAKE_CXX_STANDARD 14)

include_directories(leetcode/exercise)
include_directories(fdlib/datastruct)
#include_directories("C++ Primer/GCC_4_7_0")
#include_directories("C++ Primer/GCC_4_7_0/1")
#include_directories("C++ Primer/GCC_4_7_0/12")
#include_directories("C++ Primer/GCC_4_7_0/13")
#include_directories("C++ Primer/GCC_4_7_0/14")
#include_directories("C++ Primer/GCC_4_7_0/15")
#include_directories("C++ Primer/GCC_4_7_0/16")
#include_directories("C++ Primer/GCC_4_7_0/18")
#include_directories("C++ Primer/GCC_4_7_0/19")
#include_directories("C++ Primer/GCC_4_7_0/2")
#include_directories("C++ Primer/GCC_4_7_0/6")
#include_directories("C++ Primer/GCC_4_7_0/7")
#include_directories("C++ Primer/VisualStudio2012")
#include_directories("C++ Primer/VisualStudio2012/1")
#include_directories("C++ Primer/VisualStudio2012/12")
#include_directories("C++ Primer/VisualStudio2012/13")
#include_directories("C++ Primer/VisualStudio2012/14")
#include_directories("C++ Primer/VisualStudio2012/15")
#include_directories("C++ Primer/VisualStudio2012/16")
#include_directories("C++ Primer/VisualStudio2012/18")
#include_directories("C++ Primer/VisualStudio2012/19")
#include_directories("C++ Primer/VisualStudio2012/2")
#include_directories("C++ Primer/VisualStudio2012/6")
#include_directories("C++ Primer/VisualStudio2012/7")
#include_directories(华为OJ/future_net)

add_executable(OnlineJudge
        leetcode/main.cc
        _utils/_struct_utils.h
        fdlib/main.cc
        fdlib/datastruct/segment_tree.h
        fdlib/datastruct/segment_tree.h)
