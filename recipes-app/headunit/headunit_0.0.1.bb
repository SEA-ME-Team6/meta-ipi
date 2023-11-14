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
    install -d ${D}${bindir}/DES3/gamepad/build
    cp ${S}/gamepad/gamepad.ini ${D}${bindir}/DES3/gamepad
    cp ${B}/gamepad/libgp-movingsomeipstub.so ${D}${bindir}/DES3/gamepad/build
    cp ${B}/gamepad/libgp-lightsomeipstub.so ${D}${bindir}/DES3/gamepad/build
    install -m 0755 ${S}/gamepad/gamepad.sh ${D}${bindir}/DES3/gamepad

    install -d ${D}${bindir}/DES3/head_unit/build
    cp ${S}/head_unit/head-unit.ini ${D}${bindir}/DES3/head_unit
    cp ${B}/head_unit/libhu-gearsomeipproxy.so ${D}${bindir}/DES3/head_unit/build
    cp ${B}/head_unit/libhu-rpmsomeipproxy.so ${D}${bindir}/DES3/head_unit/build
    cp ${B}/head_unit/libhu-lightsomeipproxy.so ${D}${bindir}/DES3/head_unit/build
    install -m 0755 ${S}/head_unit/head_unit.sh ${D}${bindir}/DES3/head_unit

    install -d ${D}${bindir}/DES3/instrument_cluster/build
    cp ${S}/instrument_cluster/instrument_cluster.ini ${D}${bindir}/DES3/instrument_cluster
    cp ${B}/instrument_cluster/libic-rpmsomeipproxy.so ${D}${bindir}/DES3/instrument_cluster/build
    cp ${B}/instrument_cluster/libic-batterysomeipproxy.so ${D}${bindir}/DES3/instrument_cluster/build
    cp ${B}/instrument_cluster/libic-gearsomeipproxy.so ${D}${bindir}/DES3/instrument_cluster/build
    install -m 0755 ${S}/instrument_cluster/instrument_cluster.sh ${D}${bindir}/DES3/instrument_cluster

    install -d ${D}${bindir}/DES3/racer/build
    cp ${S}/racer/racer.ini ${D}${bindir}/DES3/racer
    cp ${B}/racer/librc-batterysomeipstub.so ${D}${bindir}/DES3/racer/build
    cp ${B}/racer/librc-gearsomeipstub.so ${D}${bindir}/DES3/racer/build
    cp ${B}/racer/librc-lightsomeipstub.so ${D}${bindir}/DES3/racer/build
    cp ${B}/racer/librc-movingsomeipproxy.so ${D}${bindir}/DES3/racer/build
    cp ${B}/racer/librc-lightsomeipproxy.so ${D}${bindir}/DES3/racer/build
    install -m 0755 ${S}/racer/racer.sh ${D}${bindir}/DES3/racer

    install -d ${D}${bindir}/DES3/rpm_sender/build
    cp ${S}/rpm_sender/rpm_sender.ini ${D}${bindir}/DES3/rpm_sender
    cp ${B}/rpm_sender/libss-rpmsomeipstub.so  ${D}${bindir}/DES3/rpm_sender/build
    install -m 0755 ${S}/rpm_sender/rpm_sender.sh ${D}${bindir}/DES3/rpm_sender
}
