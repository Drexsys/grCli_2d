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
        src/Font.cpp
        src/Font.h
        src/BigChar.cpp
        src/BigChar.h
        src/BIGSTRING.cpp
        src/BIGSTRING.h
)

target_include_directories(grCli_2d PRIVATE ${CURSES_INCLUDE_DIRS})

target_link_libraries(grCli_2d PRIVATE ${CURSES_LIBRARIES})

add_executable(dino dino-main.cpp
        dino-src/Menu.cpp
        dino-src/Menu.h
        dino-src/Game.cpp
        dino-src/Game.h

        src/Screen.cpp
        src/Screen.h
        src/Object.cpp
        src/Object.h
        src/structers.h
        src/SString.cpp
        src/SString.h
        src/Button.cpp
        src/Button.h
        dino-src/Dino.cpp
        dino-src/Dino.h
        dino-src/Enemy.cpp
        dino-src/Enemy.h
        dino-src/Score.cpp
        dino-src/Score.h
)

target_include_directories(dino PRIVATE ${CURSES_INCLUDE_DIRS})

target_link_libraries(dino PRIVATE ${CURSES_LIBRARIES})
