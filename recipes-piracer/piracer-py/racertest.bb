SUMMARY = "Recipe for PiRacer Script"
LICENSE = "CLOSED"

SRC_URI = "file://piracertest.py \
	   file://shanwan_gamepad_control.py \
"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/piracertest.py ${D}${bindir}
    install -m 0755 ${S}/shanwan_gamepad_control.py ${D}${bindir}
}

# FILES_${PN} += "${bindir}/piracertest.py"
