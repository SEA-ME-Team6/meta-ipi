SUMMARY = "Recipe for PiRacer Script"
LICENSE = "CLOSED"

SRC_URI = "file://piracertest.py"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/piracertest.py ${D}${bindir}
}

# FILES_${PN} += "${bindir}/piracertest.py"
