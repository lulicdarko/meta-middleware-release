# To support layered ipk generation

RDK_MW_ARCH ??= "${MACHINE}"

MIDDLEWARE_ARCH = "${RDK_MW_ARCH}-middleware"
PACKAGE_EXTRA_ARCHS:append = " ${MIDDLEWARE_ARCH}"

RELEASE_NUM = "8.5.1.0"

MW_IPK_PATH ?= "middleware-rel/${RELEASE_NUM}"
#wq
MW_IPK_SERVER_PATH ?= "https://partners.artifactory.comcast.com/ui/native/middleware-dbg/RDKEMW-9893/xione-bcm-flex2/ipks/debug"
MW_IPK_SERVER_PATH ?= "${RDK_ARTIFACTS_BASE_URL}/middleware-dbg/RDKEMW-9893/${RDK_MW_ARCH}/ipks/${BUILD_VARIANT}"

IPK_FEED_URIS += " \ 
                ${MIDDLEWARE_ARCH}##${MW_IPK_SERVER_PATH} "

include ${@'oss_mw.inc' if 'STACK_LAYER_OSS_SUPPORT' in d.getVar('DISTRO_FEATURES').split() else ''}
