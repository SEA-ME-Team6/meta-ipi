DESCRIPTION = "Instrument cluster Application"
LICENSE = "CLOSED"

inherit cmake_qt5
DEPENDS = " common-api-c++ common-api-c++-someip vsomeip qtbase qtquickcontrols2 qtmultimedia python3 qtbase-native"

SRC_URI += "file://CMakeLists.txt \
file://instrument_cluster.ini \
file://instrument_cluster.sh \
file://src/ \
file://src-gen/ \
"

S = "${WORKDIR}"

do_install:append() {
    install -d ${D}${bindir}/DES3/instrument_cluster/build
    cp ${S}/instrument_cluster.ini ${D}${bindir}/DES3/instrument_cluster
    cp ${B}/libic-rpmsomeipproxy.so ${D}${bindir}/DES3/instrument_cluster/build
    cp ${B}/libic-batterysomeipproxy.so ${D}${bindir}/DES3/instrument_cluster/build
    cp ${B}/libic-gearsomeipproxy.so ${D}${bindir}/DES3/instrument_cluster/build
    install -m 0755 ${S}/instrument_cluster.sh ${D}${bindir}/DES3/instrument_cluster
}

