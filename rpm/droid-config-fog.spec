%define device fog
%define vendor xiaomi

%define rpm_device fog
%define rpm_vendor xiaomi

%define vendor_pretty Xiaomi
%define device_pretty Redmi 10C

%define pixel_ratio 1.6

%define have_modem 1
%define android_version_major 14

# Device-specific ofono configuration
Provides: ofono-configs
Obsoletes: ofono-configs-mer
Obsoletes: ofono-configs-binder

# No device reset
Provides: jolla-settings-system-reset

# Device-specific usb-moded configuration
Provides: usb-moded-configs
Obsoletes: usb-moded-defaults

Obsoletes: audioflingerglue

# For bluez5
Provides: bluez5-configs
Obsoletes: bluez5-configs-mer

%define ofono_enable_plugins bluez5,hfp_ag_bluez5
%define ofono_disable_plugins bluez4,dun_gw_bluez4,hfp_ag_bluez4,hfp_bluez4,dun_gw_bluez5,hfp_bluez5

Obsoletes: qt5-qpa-surfaceflinger-plugin

BuildRequires: community-adaptation
Requires: community-adaptation

# OTA via self-hosted repo needs to have all adaptation-community repos removed
Conflicts: community-adaptation-testing
Obsoletes: community-adaptation-testing

# for wait keymaster
Requires: libgbinder-tools

%include droid-configs-device/droid-configs.inc
%include patterns/patterns-sailfish-device-adaptation-fog.inc
%include patterns/patterns-sailfish-device-configuration-fog.inc
