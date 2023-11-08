cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

project(Head_Unit VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

include_directories(
    src
    src-gen-cluster
    ~/build-commonapi/capicxx-core-runtime/include
    ~/build-commonapi/capicxx-someip-runtime/include
    ~/build-commonapi/vsomeip/interfaces
)

link_directories(
    ~/build-commonapi/capicxx-core-runtime/build
    ~/build-commonapi/capicxx-someip-runtime/build
    ~/build-commonapi/vsomeip/build
)

add_executable(Head_Unit
        src/main.cpp
        src/qml.qrc
        src/GearSelectionServer.cpp
        src/GearSelectionStubImpl.cpp
        src-gen-cluster/v1/commonapi/GearSelectionSomeIPStubAdapter.cpp
        src-gen-cluster/v1/commonapi/GearSelectionSomeIPDeployment.cpp
)

target_link_libraries(Head_Unit
  PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Network
  CommonAPI CommonAPI-SomeIP vsomeip3)
  
install(TARGETS Head_Unit DESTINATION /usr/bin)
