cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(instrument_cluster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(BUILD_COMMONAPI true) # if you want to multi compile using top op CMakeLists, 
set(BUILD_SOMEIP_LIB true) # make comment this two line.

if(BUILD_COMMONAPI)
    if (NOT TOP_CMAKE_FOUND)
        find_package(CommonAPI REQUIRED)

        include_directories(
            ${COMMONAPI_INCLUDE_DIRS}
        )
    endif()

    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

    include_directories(
        src-gen/core/common/rpm
        src-gen/core/proxy/rpm
        src-gen/core/common/battery
        src-gen/core/proxy/battery
        src-gen/core/common/gear
        src-gen/core/proxy/gear
    )

    add_executable(instrument_cluster
        src/main.cpp
        src/qml.qrc
        src/icsystem.cpp
    )

    target_link_libraries(instrument_cluster
        PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Network
        CommonAPI)


    install(TARGETS       instrument_cluster 
            DESTINATION   /usr/bin/DES3/instrument-cluster
    )
endif()

if(BUILD_SOMEIP_LIB)
    if (NOT TOP_CMAKE_FOUND)
        find_package(CommonAPI-SomeIP REQUIRED)
        find_package(vsomeip3 REQUIRED)

        include_directories(
            ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
            ${VSOMEIP3_INCLUDE_DIRS}
        )
    endif()

    include_directories(
        src-gen/someip/common/rpm
        src-gen/someip/proxy/rpm
        src-gen/someip/common/battery
        src-gen/someip/proxy/battery
        src-gen/someip/common/gear
        src-gen/someip/proxy/gear
    )

    #rpm proxy
    FILE(GLOB_RECURSE RPM_SOMEIP_PROXY_LIB_SRCS 
        src-gen/someip/proxy/rpm/*.cpp
    )
    add_library(ic-rpmsomeipproxy  SHARED
        ${RPM_SOMEIP_PROXY_LIB_SRCS}
    )
    target_link_libraries(ic-rpmsomeipproxy
        CommonAPI-SomeIP
        vsomeip3
    )

    # battery proxy
    FILE(GLOB_RECURSE BATTERY_SOMEIP_PROXY_LIB_SRCS 
        src-gen/someip/proxy/battery/*.cpp
    )
    add_library(ic-batterysomeipproxy  SHARED
        ${BATTERY_SOMEIP_PROXY_LIB_SRCS}
    )
    target_link_libraries(ic-batterysomeipproxy
        CommonAPI-SomeIP
        vsomeip3
    )

    # gear proxy
    FILE(GLOB_RECURSE GEAR_SOMEIP_PROXY_LIB_SRCS 
        src-gen/someip/proxy/gear/*.cpp
    )
    add_library(ic-gearsomeipproxy  SHARED
        ${GEAR_SOMEIP_PROXY_LIB_SRCS}
    )
    target_link_libraries(ic-gearsomeipproxy
        CommonAPI-SomeIP
        vsomeip3
    )



endif()
