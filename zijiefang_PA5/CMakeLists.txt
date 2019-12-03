cmake_minimum_required(VERSION 3.13)
project(Lab13)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)

add_executable(Lab13
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/startercode_0_12.cbp
        CMakeLists.pdf
        CMakeLists.txt
        concord.cpp
        grades.cpp
        listFuncs.cpp
        listFuncs.h
        Makefile
        melville.txt
        pa5list.cpp
        poe.txt
        README
        Table.cpp
        Table.h)
