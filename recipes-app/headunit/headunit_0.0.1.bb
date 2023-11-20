SUMMARY = "DES03: Head Unit, Instrument Cluster for Piracer"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/SEA-ME-Team6/DES_Head-Unit.git;protocol=https;branch=dev-communication"
SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git"

inherit cmake_qt5

DEPENDS = " \
	   common-api-c++ \
	   vsomeip \
	   common-api-c++-someip \
	   qtbase \
	   qtquickcontrols2 \
	   qtmultimedia \
	   python3 \
"

do_install:append() {
    cp ${S}/gamepad/gamepad.ini ${D}${bindir}/DES3/gamepad
    install -m 0755 ${S}/gamepad/gamepad.sh ${D}${bindir}/DES3/gamepad

    cp ${S}/head_unit/head-unit.ini ${D}${bindir}/DES3/head_unit
    install -m 0755 ${S}/head_unit/head_unit.sh ${D}${bindir}/DES3/head_unit

    cp ${S}/instrument_cluster/instrument_cluster.ini ${D}${bindir}/DES3/instrument_cluster
    install -m 0755 ${S}/instrument_cluster/instrument_cluster.sh ${D}${bindir}/DES3/instrument_cluster

    cp ${S}/racer/racer.ini ${D}${bindir}/DES3/racer
    install -m 0755 ${S}/racer/racer.sh ${D}${bindir}/DES3/racer

    cp ${S}/rpm_sender/rpm_sender.ini ${D}${bindir}/DES3/rpm_sender
    install -m 0755 ${S}/rpm_sender/rpm_sender.sh ${D}${bindir}/DES3/rpm_sender

    cp ${S}/battery_sender/battery_sender.ini ${D}${bindir}/DES3/battery_sender
    install -m 0755 ${S}/battery_sender/battery_sender.sh ${D}${bindir}/DES3/battery_sender

    install -d ${D}{bindir}/DES3/build
    cp ${B}/libbatterysomeipproxy.so ${D}${bindir}/DES3/build
    cp ${B}/libbatterysomeipstub.so ${D}${bindir}/DES3/build
    cp ${B}/libgearsomeipproxy.so ${D}${bindir}/DES3/build
    cp ${B}/libgearsomeipstub.so ${D}${bindir}/DES3/build
    cp ${B}/liblightsomeipproxy.so ${D}${bindir}/DES3/build
    cp ${B}/liblightsomeipstub.so ${D}${bindir}/DES3/build
    cp ${B}/libmovingsomeipproxy.so ${D}${bindir}/DES3/build
    cp ${B}/libmovingsomeipstub.so ${D}${bindir}/DES3/build
    cp ${B}/librpmsomeipproxy.so ${D}${bindir}/DES3/build
    cp ${B}/librpmsomeipstub.so ${D}${bindir}/DES3/build
}
