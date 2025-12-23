#!/bin/bash

# This should prevent `echo 1 > /dev/ipa` to crash the kernel
echo -n "/vendor/firmware" > /sys/module/firmware_class/parameters/path

mount  --bind /vendor/lib64/soundfx/libqcomvisualizer.so /vendor/lib/soundfx/libqcomvisualizer.so 
mount  --bind /vendor/lib64/soundfx/libqcompostprocbundle.so /vendor/lib/soundfx/libqcompostprocbundle.so
mount  --bind /vendor/lib64/libadm.so /vendor/lib/libadm.so
mount  --bind /vendor/lib64/hw/sound_trigger.primary.bengal.so /vendor/lib/hw/sound_trigger.primary.bengal.so
mount  --bind /vendor/lib64/libqtigef.so /vendor/lib/libqtigef.so

sh /usr/bin/droid/stune-fix.sh
echo -1000 > /proc/self/oom_score_adj
