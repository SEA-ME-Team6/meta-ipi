DESCRIPTION = "Piracer Application"
LICENSE = "CLOSED"

inherit cmake
DEPENDS = " common-api-c++ common-api-c++-someip vsomeip python3"

SRC_URI += "file://CMakeLists.txt \
file://racer.ini \
file://racer.sh \
file://src/ \
file://src-gen/ \
"

S = "${WORKDIR}"

do_install:append() {
    install -d ${D}${bindir}/DES3/racer/build
    cp ${S}/racer.ini ${D}${bindir}/DES3/racer
    cp ${B}/librc-batterysomeipstub.so ${D}${bindir}/DES3/racer/build
    cp ${B}/librc-gearsomeipstub.so ${D}${bindir}/DES3/racer/build
    cp ${B}/librc-lightsomeipstub.so ${D}${bindir}/DES3/racer/build
    cp ${B}/librc-movingsomeipproxy.so ${D}${bindir}/DES3/racer/build
    cp ${B}/librc-lightsomeipproxy.so ${D}${bindir}/DES3/racer/build
    install -m 0755 ${S}/racer.sh ${D}${bindir}/DES3/racer
}

