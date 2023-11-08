cmake_minimum_required(VERSION 3.14)

project(qt-hu VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt5 COMPONENTS Multimedia Gui REQUIRED)



set(PROJECT_SOURCES
        main.cpp
        qml.qrc
)

add_executable(qt-hu
        ${PROJECT_SOURCES}
)

target_link_libraries(qt-hu
  PRIVATE Qt5::Core Qt5::Quick Qt5::Multimedia Qt5::Gui Qt5::Quick)


install(TARGETS qt-hu DESTINATION /usr/bin)
