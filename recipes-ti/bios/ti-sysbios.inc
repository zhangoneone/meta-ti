DESCRIPTION = "TI SYS/BIOS v6 Kernel"
HOMEPAGE = "http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/bios/sysbios"
SECTION = "devel"
LICENSE = "BSD"

require ../includes/ti-paths.inc
require ../includes/ti-staging.inc
require ../includes/ti-eula-unpack.inc

S = "${WORKDIR}/bios_${PV}"

SRC_URI = "http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/bios/sysbios/${PV}/exports/bios_setuplinux_${PV}.bin;name=sysbiosbin"

BINFILE="bios_setuplinux_${PV}.bin"
TI_BIN_UNPK_CMDS="Y: q:workdir:Y"

do_install() {
    install -d ${D}${SYSBIOS_INSTALL_DIR_RECIPE}
    cp -pPrf ${S}/* ${D}${SYSBIOS_INSTALL_DIR_RECIPE}
}

ALLOW_EMPTY_${PN} = "1"
FILES_${PN}-dev += "${SYSBIOS_INSTALL_DIR_RECIPE}"

INSANE_SKIP_${PN}-dev = "arch ldflags staticdev"
