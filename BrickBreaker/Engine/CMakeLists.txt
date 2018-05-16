cmake_minimum_required(VERSION 3.8)
project(TestPrep)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(chiliGuide main.cpp
        Game.h Game.cpp Graphics.cpp Graphics.h MainWindow.cpp
        MainWindow.h Mouse.cpp Mouse.h Resource.h Resource.rc ChiliException.h ChiliWin.h Colors.h
        DXErr.cpp DXErr.h Keyboard.cpp Keyboard.h FramebufferVS.hlsl FramebufferPS.hlsl
        Engine.vcxproj Engine.vcxproj.filters Engine.vcxproj.user)