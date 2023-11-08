DESCRIPTION = "Fonts"
LICENSE = "CLOSED"

SRC_URI += "file://fonts/ \
"

S = "${WORKDIR}"

do_install:append() {
    install -d ${D}${datadir}
    cp -r ${S}/fonts ${D}${datadir}
}
