cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(head_unit)

set(CMAKE_CXX_STANDARD 11)
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
        src-gen/core/common/gear
        src-gen/core/proxy/gear
        src-gen/core/common/rpm
        src-gen/core/proxy/rpm
        src-gen/core/common/light
        src-gen/core/proxy/light
    )

    add_executable(head_unit
        src/main.cpp
        src/qml.qrc
        src/husystem.cpp
    )

    target_link_libraries(head_unit
        PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Network
        CommonAPI
    )

    install(TARGETS       head_unit 
            DESTINATION   /usr/bin/DES3/head_unit
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
        src-gen/someip/common/gear
        src-gen/someip/proxy/gear
        src-gen/someip/common/rpm
        src-gen/someip/proxy/rpm
        src-gen/someip/common/light
        src-gen/someip/proxy/light
    )

    # gear proxy
    FILE(GLOB_RECURSE GEAR_SOMEIP_PROXY_LIB_SRCS 
        src-gen/someip/proxy/gear/*.cpp
    )
    add_library(hu-gearsomeipproxy  SHARED
        ${GEAR_SOMEIP_PROXY_LIB_SRCS}
    )
    target_link_libraries(hu-gearsomeipproxy
        CommonAPI-SomeIP
        vsomeip3
    )

    # rpm proxy
    FILE(GLOB_RECURSE RPM_SOMEIP_PROXY_LIB_SRCS 
    src-gen/someip/proxy/rpm/*.cpp
    )
    add_library(hu-rpmsomeipproxy  SHARED
        ${RPM_SOMEIP_PROXY_LIB_SRCS}
    )
    target_link_libraries(hu-rpmsomeipproxy
        CommonAPI-SomeIP
        vsomeip3
    )

    # light proxy
    FILE(GLOB_RECURSE LIGHT_SOMEIP_PROXY_LIB_SRCS 
    src-gen/someip/proxy/light/*.cpp
    )
    add_library(hu-lightsomeipproxy  SHARED
        ${LIGHT_SOMEIP_PROXY_LIB_SRCS}
    )
    target_link_libraries(hu-lightsomeipproxy
        CommonAPI-SomeIP
        vsomeip3
    )



endif()
