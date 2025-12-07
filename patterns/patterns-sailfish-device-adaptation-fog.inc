# Feel free to disable non-critical HA parts during devel by commenting lines out
# Generated in hadk by executing: rpm/dhd/helpers/add_new_device.sh

%package -n patterns-sailfish-device-adaptation-fog
Summary: Jolla HW Adaptation fog
Requires: droid-hal-fog
Requires: droid-hal-fog-img-boot
Requires: droid-hal-fog-kernel-modules
Requires: droid-hal-fog-kernel-dtbo
Requires: droid-hal-fog-vendor_boot
Requires: droid-config-fog-sailfish
Requires: droid-config-fog-pulseaudio-settings
Requires: droid-config-fog-policy-settings
Requires: droid-config-fog-preinit-plugin
Requires: droid-config-fog-flashing
Requires: droid-config-fog-bluez5
Requires: droid-hal-version-fog


# Hybris packages
Requires: libhybris-libEGL
Requires: libhybris-libGLESv2
Requires: libhybris-libwayland-egl

# For mount partitions
# Requires: parse-android-dynparts

# Bluetooth
Requires: bluebinder

# Telephony
Requires: ofono-binder-plugin
Requires: dummy_netd
# Requires: ofono-binder-plugin-ext-qti
# Requires: fake-qcrilmsgtunnel

# Sensors
Requires: hybris-libsensorfw-qt5

# Vibra
Requires: ngfd-plugin-native-vibrator
Requires: libngf-qt5-qtfeedback

# Needed for /dev/touchscreen symlink
Requires: qt5-plugin-generic-evdev

Requires: pulseaudio-modules-droid
Requires: pulseaudio-modules-droid-hidl

# The -dummy-af is needed for newer devices that run the main
# audiosystem-passthrough in qti mode (e.g. >=Android 9 Qualcomm),
# to fix non-responding Camera app and/or voice during a phone call:
Requires: audiosystem-passthrough-dummy-af

# droid-bthelper monitors bluetooth headsets and notifies android
# audio service. after such notification, phone calls are routed through
# bluetooth headset
Requires: droid-bthelper

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
Requires: sailfish-devicelock-fpd
Requires: sailfish-fpd-community
Requires: sailfish-fpd-community-test
Requires: droid-fake-crypt
Obsoletes: jolla-devicelock-daemon-encsfa

# enable device lock and allow to select untrusted software
#Requires: jolla-devicelock-daemon-encsfa

# /home encryption
Requires: droid-hwcrypt
Requires: sailfish-device-encryption-community
Requires: sailfish-device-encryption-community-droid

# For GPS
Requires: geoclue-provider-hybris

# For FM radio on some QCOM devices
Requires: qt5-qtmultimedia-plugin-mediaservice-irisradio
Requires: jolla-mediaplayer-radio

# NFC support
# 1. binder plugin requires Android 8 or a newer base
# 2. pn54x plugin talks directly to pn54x driver
# These plugins are mutually exclusive, you need to pick one:
Requires: nfcd-binder-plugin
#Requires: nfcd-pn54x-plugin

%description -n patterns-sailfish-device-adaptation-fog
Pattern with packages for fog HW Adaptation

# For suspend to work with enabled Wi-Fi on newer Qualcomm devices
Requires: sailfish-connman-plugin-suspend

# Splash screen - it has to be stopped for composer to work, but somehow
# it is required for high boot success rate
Requires: yamuisplash

%files -n patterns-sailfish-device-adaptation-fog
