cmake_minimum_required(VERSION 3.31)
project(grCli_2d)

set(CMAKE_CXX_STANDARD 20)

find_package(Curses REQUIRED)

add_executable(grCli_2d main.cpp
        src/Screen.cpp
        src/Screen.h
        src/Object.cpp
        src/Object.h
        src/structers.h
        src/SString.cpp
        src/SString.h
        src/Button.cpp
        src/Button.h
)

target_include_directories(grCli_2d PRIVATE ${CURSES_INCLUDE_DIRS})

target_link_libraries(grCli_2d PRIVATE ${CURSES_LIBRARIES})

