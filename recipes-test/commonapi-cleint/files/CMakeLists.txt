cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

#find_package(PythonLibs REQUIRED)

include_directories(
    src
    #../common
    src-gen-cluster
    ~/build-commonapi/capicxx-core-runtime/include
    ~/build-commonapi/capicxx-someip-runtime/include
    ~/build-commonapi/vsomeip/interface
    #${PYTHON_INCLUDE_DIRS}
)

link_directories(
    ~/build-commonapi/capicxx-core-runtime/build
    ~/build-commonapi/capicxx-someip-runtime/build
    ~/build-commonapi/vsomeip/build
)

add_executable(Yocto_Test_Client
        src/main.cpp
        #src/Gamepad.cpp
        src/SpeedStatusClient.cpp
        #../common/piracer.cpp
        #../common/PythonManager.cpp
        src-gen-cluster/v1/commonapi/SpeedStatusSomeIPDeployment.cpp
        src-gen-cluster/v1/commonapi/SpeedStatusSomeIPProxy.cpp
)
#target_link_libraries(Gamepad CommonAPI CommonAPI-SomeIP vsomeip3 ${PYTHON_LIBRARIES})
target_link_libraries(Yocto_Test_Client CommonAPI CommonAPI-SomeIP vsomeip3 )



