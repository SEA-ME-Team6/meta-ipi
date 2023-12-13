SUMMARY = "Simple abstraction layer for PiRacer and PiRacer Pro"
HOMEPAGE = "https://github.com/twyleg/piracer_py"
AUTHOR = "Torsten Wylegala <mail@twyleg.de>"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=6decff0ca0b506b9b7a5f54ac3d286f8"

SRC_URI = " \
	git://github.com/twyleg/piracer_py.git;protocol=https;nobranch=1 \
	file://activate-buttons.patch \
"
SRCREV = "7314ec1874388dc4ebc863aa429f82222b534ac1"

S = "${WORKDIR}/git"

inherit setuptools3

DEPENDS += "python3-setuptools-scm-native"
RDEPENDS:${PN} += " \
    python3-wheel \
    rpi-gpio \
    python3-adafruit-circuitpython-pca9685 \
    python-adafruit-circuitpython-ina219 \
    python-adafruit-circuitpython-ssd1306 \
    opencv \
    python3-core \
"

COMPATIBLE_HOST:libc-musl:class-target = "null"
