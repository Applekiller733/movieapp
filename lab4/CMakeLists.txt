cmake_minimum_required(VERSION 3.27)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS Core Widgets WebView REQUIRED)



add_executable(lab4
        main.cpp
        Domain/domain.cpp
        Domain/domain.h
        Repository/repository.cpp
        Repository/repository.h
        Repository/repotests.cpp
        Repository/repotests.h
        Services/services.cpp
        Services/services.h
        UI/ui.cpp
        UI/ui.h
        Services/servicestests.cpp
        Services/servicestests.h
        Domain/jsondomaintest.cpp
        Domain/jsondomaintest.h
        Services/jsonservicestests.cpp
        Services/jsonservicestests.h
        GUI/GUI.cpp
        GUI/GUI.h
)

target_link_libraries(lab4 Qt6::Core Qt6::Widgets Qt6::WebView)