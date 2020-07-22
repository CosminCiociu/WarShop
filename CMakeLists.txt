cmake_minimum_required(VERSION 3.7)
project(Project2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Admin.cpp Admin.h Meniu.cpp Meniu.h LoginAsUser.cpp LoginAsUser.h RemoveLine.cpp RemoveLine.h)
add_executable(Project2 ${SOURCE_FILES})