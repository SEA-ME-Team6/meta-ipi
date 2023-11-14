cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(gamepad)

set(BUILD_COMMONAPI true) # if you want to multi compile using top op CMakeLists, 
set(BUILD_SOMEIP_LIB true) # make comment this two line.

if(BUILD_COMMONAPI)
    if (NOT TOP_CMAKE_FOUND)
        find_package(CommonAPI REQUIRED)

        include_directories(
            ${COMMONAPI_INCLUDE_DIRS}
        )
    endif()

    find_package(PythonLibs REQUIRED)

    include_directories(
        src-gen/core/common/moving
        src-gen/core/stub/moving
        src-gen/core/skel/moving
        src-gen/core/common/light
        src-gen/core/stub/light
        src-gen/core/skel/light
        ${PYTHON_INCLUDE_DIRS}
    )

    add_executable(gamepad
        src/main.cpp
        src/gamepad.cpp
        src/gamepadsystem.cpp
        src/movingstubImpl.cpp
        src/lightstubImpl.cpp

    )

    target_link_libraries(gamepad
        PRIVATE           CommonAPI
        ${PYTHON_LIBRARIES}
    )

    install(TARGETS       gamepad 
            DESTINATION   /usr/bin/DES3/gamepad
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
        src-gen/someip/common/moving
        src-gen/someip/stub/moving
        src-gen/someip/common/light
        src-gen/someip/stub/light
    )

    # moving stub
    FILE(GLOB_RECURSE MOVING_SOMEIP_STUB_LIB_SRCS 
        src-gen/someip/stub/moving/*.cpp
    )
    add_library(gp-movingsomeipstub  SHARED
        ${MOVING_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(gp-movingsomeipstub
        CommonAPI-SomeIP
        vsomeip3
    )

    # light stub
    FILE(GLOB_RECURSE LIGHT_SOMEIP_STUB_LIB_SRCS 
        src-gen/someip/stub/light/*.cpp
    )
    add_library(gp-lightsomeipstub  SHARED
        ${LIGHT_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(gp-lightsomeipstub
        CommonAPI-SomeIP
        vsomeip3
    )


endif()
