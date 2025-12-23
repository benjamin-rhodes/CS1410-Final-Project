# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(BaronySokoban VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(BaronySokoban
    main.cpp
    Game.h
    Player.h
    Board.h
)
