#!/bin/bash

mkdir -p /vendor /odm/etc /product /system_ext /mnt/vendor/persist /odm_root
mount --bind /odm_root/etc /odm/etc
#mount  --bind /vendor/lib64/soundfx/libqcomvisualizer.so /vendor/lib/soundfx/libqcomvisualizer.so
#mount  --bind /vendor/lib64/soundfx/libqcompostprocbundle.so /vendor/lib/soundfx/libqcompostprocbundle.so
#mount  --bind /vendor/lib64/libadm.so /vendor/lib/libadm.so
#mount  --bind /vendor/lib64/hw/sound_trigger.primary.bengal.so /vendor/lib/hw/sound_trigger.primary.bengal.so
#mount  --bind /vendor/lib64/libqtigef.so /vendor/lib/libqtigef.so
# bind custom patches
#mount --bind $lipstick_patch /usr/share/lipstick-jolla-home-qt5/statusarea/StatusArea.qml

# bt
mount --bind /usr/libexec/droid-hybris/system/bluebinder_wait.sh /usr/bin/droid/bluebinder_wait.sh

# waydroid binderfs
cd /dev/
ln -s binderfs/*puddle* .
chmod 666 binderfs/*puddle

echo -1000 > /proc/self/oom_score_adj
