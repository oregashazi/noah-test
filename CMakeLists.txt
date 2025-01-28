cmake_minimum_required(VERSION 3.30)
project(noah-git)

set(CMAKE_CXX_STANDARD 20)

add_executable(noah-git main.cpp
        User.cpp
        User.h
        Game.cpp
        Game.h
        GoodCurrentGames.cpp
        GoodCurrentGames.h)
