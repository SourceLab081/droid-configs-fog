#!/bin/bash

mkdir /odm/etc
mount --bind /odm_root/etc /odm/etc
# accesible binder devices in /dev
ln -sf /dev/binderfs/* /dev/
#mount --bind /usr/libexec/droid-hybris/system/lib64/hw/audio.hidl_compat.default.so /vendor/lib64/hw/audio.primary.kona.so

# wlan
#mount --bind /lib/modules/`uname -r`/wlan.ko /vendor/lib/modules/qca_cld3_wlan.ko

# bt
chmod +x /usr/libexec/droid-hybris/system/bluebinder_wait.sh
mount --bind /usr/libexec/droid-hybris/system/bluebinder_wait.sh /usr/bin/droid/bluebinder_wait.shsh /usr/bin/droid/stune-fix.sh