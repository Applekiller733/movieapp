cmake_minimum_required(VERSION 3.27)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4 main.cpp
        UI/ui.cpp
        UI/ui.h
        Domain/domain.cpp
        Domain/domain.h
        Services/services.cpp
        Services/services.h
        Repository/repository.cpp
        Repository/repository.h
        Repository/repotests.cpp
        Repository/repotests.h)
