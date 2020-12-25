cmake_minimum_required(VERSION 3.9)
project(cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp
        basics/cplus.cpp
        cpp11/move.cpp
        cpp11/rvals.cpp
        cpp11/c11.cpp
        cpp11/c11_2.cpp
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
        concur/mythread.cpp
        templates/factorial.cpp
        templates/special.cpp
        templates/partial.cpp
        appl/extract.cpp
        cpp17/optionals.cpp
        cpp17/stringview.cpp)
