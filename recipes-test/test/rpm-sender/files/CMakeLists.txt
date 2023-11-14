cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(rpm_sender)

set(BUILD_COMMONAPI true) # if you want to multi compile using top op CMakeLists, 
set(BUILD_SOMEIP_LIB true) # make comment this two line.

if(BUILD_COMMONAPI)
    if (NOT TOP_CMAKE_FOUND)
        find_package(CommonAPI REQUIRED)

        include_directories(
            ${COMMONAPI_INCLUDE_DIRS}
        )
    endif()

    include_directories(
        src-gen/core/common/rpm
        src-gen/core/stub/rpm
        src-gen/core/skel/rpm
    )

    add_executable(rpm_sender
        src/main.cpp
        src/canreceive.cpp
        src/rpmsystem.cpp
        src/rpmstubImpl.cpp
    )

    target_link_libraries(rpm_sender
        PRIVATE CommonAPI
    )

    install(TARGETS       rpm_sender 
            DESTINATION   /usr/bin/DES3/rpm_sender
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
        src-gen/someip/stub/rpm
    )

    # rpm stub
    FILE(GLOB_RECURSE RPM_SOMEIP_STUB_LIB_SRCS 
        src-gen/someip/stub/rpm/*.cpp
    )
    add_library(ss-rpmsomeipstub  SHARED
        ${RPM_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(ss-rpmsomeipstub
        CommonAPI-SomeIP
        vsomeip3
    )


endif()
