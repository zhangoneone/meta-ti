DESCRIPTION = "TI Network abstraction layer LLD library "

DEPENDS = "common-csl-ip rm-lld qmss-lld hplib pa-lld sa-lld pktlib"

include nwal-lld.inc

EXTRA_OEMAKE += "-f makefile_armv7 PDK_INSTALL_PATH=${STAGING_INCDIR}"

do_compile () {
	for device in ${DEVICELIST}
	do
		for choice in ${CHOICELIST}
		do
			oe_runmake clean NWAL_INC_DIR=${BASEDIR} NWAL_SRC_DIR=${S} USEDYNAMIC_LIB="$choice" DEVICE="$device"
			oe_runmake lib NWAL_INC_DIR=${BASEDIR} NWAL_SRC_DIR=${S} USEDYNAMIC_LIB="$choice" DEVICE="$device"
		done
	done
}

do_install () {
	for device in ${DEVICELIST}
	do
		oe_runmake install INSTALL_INC_BASE_DIR=${D}${includedir} INSTALL_LIB_BASE_DIR=${D}${libdir} INSTALL_BIN_BASE_DIR=${D}${bindir} DEVICE="$device"
	done
}
