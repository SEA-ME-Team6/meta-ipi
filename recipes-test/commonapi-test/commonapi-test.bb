DESCRIPTION = "CommonAPI test"
   
inherit cmake

LICENSE = "CLOSED"

DEPENDS = " common-api-c++ common-api-c++-someip vsomeip"
RDEPENDS:{PN} += "common-api-c++ common-api-c++-someip vsomeip"
    
SRC_URI = " \     
            file://CMakeLists.txt \
            file://src/ \
	    file://src-gen-manager/ \
	    "

S = "${WORKDIR}"
  
    
#do_install(){
#    install -d ${D}${bindir}
#    install -m 0755 SpeedClient ${D}${bindir}
#    install -m 0755 RpmClient ${D}${bindir}
#    install -m 0755 ManagerService ${D}${bindir}
#}

