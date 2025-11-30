cmake_minimum_required(VERSION 4.0)
project(cs116_Fall2025_connectFour)

set(CMAKE_CXX_STANDARD 14)

add_executable(cs116_Fall2025_connectFour
        main.cpp
        Chip.cpp
        Chip.h
        Board.cpp
        Board.h
        Game.cpp
        Game.h)
