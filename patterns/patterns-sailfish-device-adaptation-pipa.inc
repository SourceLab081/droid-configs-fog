# Feel free to disable non-critical HA parts during devel by commenting lines out
# Generated in hadk by executing: rpm/dhd/helpers/add_new_device.sh

%package -n patterns-sailfish-device-adaptation-pipa
Summary: Jolla HW Adaptation pipa
Requires: droid-hal-pipa
Requires: droid-hal-pipa-img-boot
Requires: droid-hal-pipa-kernel-modules
Requires: droid-hal-pipa-kernel-dtbo
Requires: droid-hal-pipa-vendor_boot
Requires: droid-config-pipa-sailfish
Requires: droid-config-pipa-pulseaudio-settings
Requires: droid-config-pipa-policy-settings
Requires: droid-config-pipa-preinit-plugin
Requires: droid-config-pipa-flashing
Requires: droid-config-pipa-bluez5
Requires: droid-hal-version-pipa

# Hybris packages
Requires: libhybris-libEGL
Requires: libhybris-libGLESv2
Requires: libhybris-libwayland-egl

# For mount partitions
Requires: parse-android-dynparts

# Bluetooth
Requires: bluebinder

# Telephony
Requires: ofono-binder-plugin
Requires: dummy_netd

# Sensors
Requires: hybris-libsensorfw-qt5

# Needed for /dev/touchscreen symlink
Requires: qt5-plugin-generic-evdev

Requires: pulseaudio-modules-droid
Requires: pulseaudio-modules-droid-hidl

# The -dummy-af is needed for newer devices that run the main
# audiosystem-passthrough in qti mode (e.g. >=Android 9 Qualcomm),
# to fix non-responding Camera app and/or voice during a phone call:
Requires: audiosystem-passthrough-dummy-af

# for audio recording to work:
Requires: qt5-qtmultimedia-plugin-mediaservice-gstmediacapture

# These need to be per-device due to differing backends (fbdev, eglfs, hwc, ..?)
Requires: qt5-qtwayland-wayland_egl
Requires: qt5-qpa-hwcomposer-plugin
Requires: qtscenegraph-adaptation

# For hybris devices with droidmedia, see HADK pdf for more information
Requires: gstreamer1.0-droid
Requires: gmp-droid

# USB mode controller
Requires: usb-moded

# hammerhead, grouper, and maguro use this in scripts, so include for all
Requires: rfkill

# enable device lock and allow to select untrusted software
Requires: jolla-devicelock-daemon-encsfa

%description -n patterns-sailfish-device-adaptation-pipa
Pattern with packages for pipa HW Adaptation

%files -n patterns-sailfish-device-adaptation-pipa
