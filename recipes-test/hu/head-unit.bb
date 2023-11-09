DESCRIPTION = "HeadUnit Application"
LICENSE = "CLOSED"

inherit cmake_qt5
DEPENDS = " \
	   common-api-c++ \
	   common-api-c++-someip \
	   vsomeip \
	   qtbase \
	   qtquickcontrols2 \
	   qtmultimedia \
	   python3 \
	   qtbase-native \
"

SRC_URI += "file://CMakeLists.txt \
file://src/ \
file://src/qml/ \
file://src-gen-cluster/ \
"

S = "${WORKDIR}"

EXTRA_OECMAKE += " \
		-DCMAKE_INCLUDE_PATH=${STAGING_INCDIR} \
		-DCMAKE_LIBRARY_PATH=${STAGING_LIBDIR} \
"

