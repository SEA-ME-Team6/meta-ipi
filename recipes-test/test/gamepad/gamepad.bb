DESCRIPTION = "Gamepad Application"
LICENSE = "CLOSED"

inherit cmake
DEPENDS = " common-api-c++ common-api-c++-someip vsomeip python3"

SRC_URI += "file://CMakeLists.txt \
file://gamepad.ini \
file://gamepad.sh \
file://src/ \
file://src-gen/ \
"

S = "${WORKDIR}"

do_install:append() {
    install -d ${D}${bindir}/DES3/gamepad/build
    cp ${S}/gamepad.ini ${D}${bindir}/DES3/gamepad
    cp ${B}/libgp-movingsomeipstub.so ${D}${bindir}/DES3/gamepad/build
    cp ${B}/libgp-lightsomeipstub.so ${D}${bindir}/DES3/gamepad/build
    install -m 0755 ${S}/gamepad.sh ${D}${bindir}/DES3/gamepad
}

