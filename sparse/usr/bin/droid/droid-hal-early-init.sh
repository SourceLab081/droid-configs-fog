#!/bin/bash

mkdir /odm/etc
mount --bind /odm_root/etc /odm/etc
mount --bind /usr/libexec/droid-hybris/system/lib64/hw/audio.hidl_compat.default.so /vendor/lib64/hw/audio.primary.kona.so
mount --bind /usr/libexec/droid-hybris/system/bin/xiaomi-keyboard /vendor/bin/xiaomi-keyboard
