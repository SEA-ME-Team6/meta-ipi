DESCRIPTION = "QT HeadUnit Application"
LICENSE = "CLOSED"

inherit cmake_qt5
DEPENDS = " common-api-c++ common-api-c++-someip vsomeip qtbase qtquickcontrols2 qtmultimedia python3 qtbase-native"

SRC_URI += "file://src/CMakeLists.txt \
file://src/ \
"

S = "${WORKDIR}/src"

