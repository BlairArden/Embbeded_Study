cmake_minimum_required(VERSION 3.30)
project(Embedded_dev)

set(CMAKE_CXX_STANDARD 11)

add_executable(Embedded_dev main.cpp
        Task_1/Character.cpp
        Task_1/Character.h
        Task_1/Hero.cpp
        Task_1/Hero.h
        Task_1/Constant.cpp
        Task_1/Constant.h
        Task_1/Monster.cpp
        Task_1/Monster.h)
