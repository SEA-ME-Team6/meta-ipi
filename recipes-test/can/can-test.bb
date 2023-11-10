SUMMARY = "Recipe for CAN test"
LICENSE = "CLOSED"

SRC_URI = "file://can_receiver.py \
"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/can_receiver.py ${D}${bindir}
}

