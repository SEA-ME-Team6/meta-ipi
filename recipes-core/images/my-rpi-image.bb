SUMMARY = "My image for yocto"
inherit my-rpi-image

LINGUAS_KO_KR = "ko-kr"
LINGUAS_EN_US = "en-us"
IMAGE_LINGUAS = "${LINGUAS_KO_KR} ${LINGUAS_EN_US}"
IMAGE_OVERHEAD_FACTOR = "1.3"

inherit extrausers 

EXTRA_USERS_PARAMS = "\
 	groupadd seame; \
	useradd -p \$(openssl passwd 1234) team6; \
       	useradd -a -G sudo team6; \
	useradd -g seame team6; \
"	

KIRKSTONE_LOCAL_GETTY ?= " \
                        ${IMAGE_ROOTFS}${systemd_system_unitdir}/serial-getty@.service \
                        ${IMAGE_ROOTFS}${systemd_system_unitdir}/getty@.service \
"    
 
local_autologin () {
    sed -i -e 's/^\(ExecStart *=.*getty \)/\1--autologin root /' ${KIRKSTONE_LOCAL_GETTY}
}
 
ROOTFS_POSTPROCESS_COMMAND += "local_autologin;"
