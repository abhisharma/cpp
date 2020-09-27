cmake_minimum_required(VERSION 3.9)
project(cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp
        basics/cplus.cpp
        basics/move.cpp
        basics/rvals.cpp
        basics/c11.cpp
        basics/c11Other.cpp
        concur/concurrency.cpp
        concur/concurrency2.cpp
        stl/deque.cpp
        stl/funcobjects.cpp
        templates/functempl.cpp
        stl/list.cpp
        main.cpp
        stl/map.cpp
        stl/set.cpp
        stl/vector.cpp
        appl/spreadsheet.cpp
        templates/classtempl.cpp
        basics/arrays.cpp
        basics/arrayref.cpp
        concur/mythread.cpp templates/factorial.cpp templates/special.cpp templates/partial.cpp appl/extract.cpp)
