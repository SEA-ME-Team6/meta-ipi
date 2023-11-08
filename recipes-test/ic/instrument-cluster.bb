DESCRIPTION = "Instrument Cluster Application"
LICENSE = "CLOSED"

inherit cmake_qt5
DEPENDS = " common-api-c++ common-api-c++-someip vsomeip qtbase qtquickcontrols2"

SRC_URI += "file://CMakeLists.txt \
file://src/ \
file://src/qml/ \
file://src-gen-cluster/ \
"

S = "${WORKDIR}"

