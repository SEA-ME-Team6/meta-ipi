DESCRIPTION = "Qt component for application lifecycle management"
LICENSE = "LICENSE.FDL | LICENSE.GPL2 | LICENSE.GPL3 | LICENSE.GPL3-EXCEPT | LICENSE.LGPL3 | The-Qt-Company-Commercial"
LIC_FILES_CHKSUM = " \
    file://LICENSE.FDL;md5=6d9f2a9af4c8b8c3c769f6cc1b6aaf7e \
    file://LICENSE.GPL2;md5=b234ee4d69f5fce4486a80fdaf4a4263 \
    file://LICENSE.GPL3;md5=d32239bcb673463ab874e80d47fae504 \
    file://LICENSE.GPL3-EXCEPT;md5=763d8c535a234d9a3fb682c7ecb6c073 \
    file://LICENSE.LGPL3;md5=e6a600fd5e1d9cbde2d983680233ad02 \
"

S = "${WORKDIR}/git"

inherit qmake5

SRC_URI = " \
git://github.com/qt/qtapplicationmanager.git;protocol=https;nobranch=1 \
"

SRCREV = "12643d292d7404d9b81ce494dc265e0c82e42ca3"

DEPENDS = " \
qtbase \
qtdeclarative \
libyaml \
libarchive \
openssl \
qtwayland \
"
DEPENDS:append:libc-musl = " libexecinfo"


PACKAGECONFIG ?= "${@bb.utils.contains('DISTRO_FEATURES', 'wayland', 'multi-process', '', d)}"

PACKAGECONFIG[multi-process] = "-DFEATURE_am_multi_process=ON, -DFEATURE_am_multi_process=OFF, qtwayland qtwayland-native"

PACKAGECONFIG[tools-only] = ""
PACKAGECONFIG:class-native ??= "tools-only"
PACKAGECONFIG:class-nativesdk ??= "tools-only"

do_configure() {
   qmake ../git
}

FILES:${PN} += " \
/usr/share/examples/applicationmanager/* \
/usr/lib/libQt5AppMan* \
/usr/lib/mkspecs/* \
/usr/lib/libqtyaml.prl \
/usr/lib/libqtarchive.prl \
"
