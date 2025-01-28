cmake_minimum_required(VERSION 3.30)
project(uebung2020911)

set(CMAKE_CXX_STANDARD 20)

add_executable(uebung2020911 main.cpp
        User.cpp
        User.h
        Game.cpp
        Game.h
        GoodCurrentGames.cpp
        GoodCurrentGames.h)
