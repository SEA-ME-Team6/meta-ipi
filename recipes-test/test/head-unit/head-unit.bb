DESCRIPTION = "HeadUnit Application"
LICENSE = "CLOSED"

inherit cmake_qt5
DEPENDS = " common-api-c++ common-api-c++-someip vsomeip qtbase qtquickcontrols2 qtmultimedia python3 qtbase-native"

SRC_URI += "file://CMakeLists.txt \
file://head-unit.ini \
file://head_unit.sh \
file://src/ \
file://src-gen/ \
"

S = "${WORKDIR}"

do_install:append() {
    install -d ${D}${bindir}/DES3/head_unit/build
    cp ${S}/head-unit.ini ${D}${bindir}/DES3/head_unit
    cp ${B}/libhu-gearsomeipproxy.so ${D}${bindir}/DES3/head_unit/build
    cp ${B}/libhu-rpmsomeipproxy.so ${D}${bindir}/DES3/head_unit/build
    cp ${B}/libhu-lightsomeipproxy.so ${D}${bindir}/DES3/head_unit/build
    install -m 0755 ${S}/head_unit.sh ${D}${bindir}/DES3/head_unit
}

