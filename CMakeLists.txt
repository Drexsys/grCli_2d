cmake_minimum_required(VERSION 4.2)
project(grCli_2d)

set(CMAKE_CXX_STANDARD 20)

add_executable(grCli_2d main.cpp
        src/Screen.cpp
        src/Screen.h
        src/Object.cpp
        src/Object.h
        src/structers.h)
