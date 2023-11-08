SUMMARY = "for Automount"
LICENSE = "CLOSED"

SRC_URI += "file://automount.sh \
	    file://automount.service \
	"
SYSTEMD_SERVICE:${PN} = "automount.service"

do_install:append() {
	install -d ${D}${sysconfdir}/automount
	install -d ${D}${systemd_system_unitdir}

	install -m 0755 ${WORKDIR}/automount.sh ${D}${sysconfdir}/automount/automount.sh
	install -m 0644 ${WORKDIR}/automount.service ${D}${systemd_system_unitdir}
}

FILES:${PN} += "/lib/systemd/system/automount.service"
