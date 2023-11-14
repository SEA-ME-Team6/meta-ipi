DESCRIPTION = "RPMSender Application"
LICENSE = "CLOSED"

inherit cmake
DEPENDS = " common-api-c++ common-api-c++-someip vsomeip"

SRC_URI += "file://CMakeLists.txt \
file://rpm_sender.ini \
file://rpm_sender.sh \
file://src/ \
file://src-gen/ \
"

S = "${WORKDIR}"

do_install:append() {
    install -d ${D}${bindir}/DES3/rpm_sender/build
    cp ${S}/rpm_sender.ini ${D}${bindir}/DES3/rpm_sender
    cp ${B}/libss-rpmsomeipstub.so  ${D}${bindir}/DES3/rpm_sender/build
    install -m 0755 ${S}/rpm_sender.sh ${D}${bindir}/DES3/rpm_sender
}

