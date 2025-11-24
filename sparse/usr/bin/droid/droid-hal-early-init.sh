#/bin/sh
super_part=/dev/sda9
# Partitions mounted in /vendor/*
modem_part=/dev/sde4
#modem_part=/dev/sde26
dsp_part=/dev/sde9
#dsp_part=/dev/sde31
bluetooth_part=/dev/sde5
#bluetooth_part=/dev/sde27
 
dmesg_info() {
    echo "[mount-partitions.sh] $@" > /dev/kmsg
}
 
dmesg_info "Map dynamic partitions"
dmsetup create --concise "$(/usr/bin/parse-android-dynparts $super_part)"
 
dmesg_info "Dynamic partitions: $(ls /dev/mapper/dynpart-*)"
 
dmesg_info "Mount dynamic partitions"
mkdir -p /system_root /system_ext /vendor /odm /product /mnt
 
dmesg_info "$(mount -v -o ro /dev/mapper/dynpart-system  /system_root)"
dmesg_info "$(mount --bind /system_root/system /system)"
dmesg_info "$(mount -v -o ro /dev/mapper/dynpart-system_ext /system_ext)"
dmesg_info "$(mount -v -o ro /dev/mapper/dynpart-vendor  /vendor)"
dmesg_info "$(mount -v -o ro /dev/mapper/dynpart-odm   /odm)"
dmesg_info "$(mount -v -o ro /dev/mapper/dynpart-product /product)"
 
dmesg_info "Mount /vendor/*"
dmesg_info "$(mount -v $modem_part      /vendor/firmware_mnt)"
dmesg_info "$(mount -v $dsp_part        /vendor/dsp)"
dmesg_info "$(mount -v $bluetooth_part  /vendor/bt_firmware)"
 
# comment out when everything works
dmesg_info "$(findmnt)"
# Sound fix.
#ln -s /usr/lib64/pulse-14.2/modules/libdroid-util.so /usr/lib64/pulseaudio/libdroid-util.so
# Make pulseaudio happy!
# mount --bind /vendor/lib64/libqtigef.so /vendor/lib/libqtigef.so
# mount --bind /vendor/lib64/soundfx/libqcompostprocbundle.so /vendor/lib/soundfx/libqcompostprocbundle.so
# mount --bind /vendor/lib64/soundfx/libqcomvisualizer.so /vendor/lib/soundfx/libqcomvisualizer.so

# sh /usr/bin/droid/stune-fix.sh
