DESCRIPTION = "CommonAPI test"
   
inherit cmake

LICENSE = "CLOSED"

DEPENDS = " common-api-c++ common-api-c++-someip vsomeip"
RDEPENDS:{PN} += "common-api-c++ common-api-c++-someip vsomeip"
    
SRC_URI = " \     
            file://CMakeLists.txt \
            file://src/main.cpp \
	    file://src/SpeedStatusClient.cpp \
            file://src/SpeedStatusClient.hpp \
	    file://src-gen-cluster/ \
	    "

S = "${WORKDIR}"
  
    
do_install(){
    install -d ${D}${bindir}
    install -m 0755 Yocto_Test_Client ${D}${bindir}
}

