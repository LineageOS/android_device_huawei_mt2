# Copyright (C) 2015 The CyanogenMod Project
# Copyright (C) 2011 The Android Open-Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Assert
# Stock values:
#   ro.product.device=hwMT2L03
#   ro.build.product=MT2L03
# Also:
#   ro.build.id=HuaweiMT2L03
TARGET_OTA_ASSERT_DEVICE := MT2L03,hwMT2L03,mt2,mt2l03

# Architecture
TARGET_ARCH := arm
TARGET_ARCH_VARIANT := armv7-a-neon
TARGET_CPU_ABI := armeabi-v7a
TARGET_CPU_ABI2 := armeabi
TARGET_CPU_VARIANT := krait
TARGET_CPU_MEMCPY_BASE_OPT_DISABLE := true

# Audio
BOARD_USES_ALSA_AUDIO := true

# Bluetooth
BLUETOOTH_HCI_USE_MCT := true
BOARD_HAVE_BLUETOOTH := true
BOARD_HAVE_BLUETOOTH_QCOM := true
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := device/huawei/mt2/bluetooth

# Board
BOARD_USES_QCOM_HARDWARE := true
COMMON_GLOBAL_CFLAGS += -DQCOM_HARDWARE
TARGET_BOARD_PLATFORM := msm8226
TARGET_BOOTLOADER_BOARD_NAME := MT2L03

# Build
TARGET_NO_BOOTLOADER := true
TARGET_NO_RADIOIMAGE := true
TARGET_SPECIFIC_HEADER_PATH := device/huawei/mt2/include

# Camera
COMMON_GLOBAL_CPPFLAGS += -DNEEDS_VECTORIMPL_SYMBOLS
USE_DEVICE_SPECIFIC_CAMERA := true

# Filesystem
BOARD_FLASH_BLOCK_SIZE := 131072 # (BOARD_KERNEL_PAGESIZE * 64)
BOARD_BOOTIMAGE_PARTITION_SIZE := 67108864
BOARD_CACHEIMAGE_PARTITION_SIZE := 201326592
BOARD_PERSISTIMAGE_PARTITION_SIZE := 8388608
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 67108864
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1879048192
BOARD_USERDATAIMAGE_PARTITION_SIZE := 12803095552
TARGET_USERIMAGES_USE_EXT4 := true

# FM
AUDIO_FEATURE_ENABLED_FM := true
TARGET_QCOM_NO_FM_FIRMWARE := true

# Fonts
EXTENDED_FONT_FOOTPRINT := true

# Graphics
TARGET_CONTINUOUS_SPLASH_ENABLED := true
TARGET_USES_C2D_COMPOSITION := true
TARGET_USES_ION := true
USE_OPENGL_RENDERER := true

# Init
TARGET_INIT_VENDOR_LIB := libinit_mt2
TARGET_LIBINIT_DEFINES_FILE := device/huawei/mt2/init/init_mt2.c

# Kernel
BOARD_CUSTOM_BOOTIMG_MK := device/huawei/mt2/mkbootimg.mk
BOARD_KERNEL_BASE := 0x0
BOARD_KERNEL_CMDLINE := androidboot.hardware=qcom user_debug=31 msm_rtb.filter=0x37
BOARD_KERNEL_PAGESIZE := 2048
BOARD_KERNEL_SEPARATED_DT := true
BOARD_MKBOOTIMG_ARGS := --ramdisk_offset 0x02000000
TARGET_KERNEL_CONFIG := cyanogenmod_mt2_defconfig
TARGET_KERNEL_SOURCE := kernel/huawei/msm8928

# Lights
TARGET_PROVIDES_LIBLIGHT := true

# Power
TARGET_POWERHAL_VARIANT := qcom

# Recovery
TARGET_RECOVERY_DEVICE_MODULES := chargeled
TARGET_RECOVERY_FSTAB = device/huawei/mt2/rootdir/fstab.qcom
TARGET_RECOVERY_PIXEL_FORMAT := "RGBX_8888"
BOARD_CHARGING_CMDLINE_NAME := "androidboot.huawei_bootmode"
BOARD_CHARGING_CMDLINE_VALUE := "hwcharger"

# Release tools
TARGET_RELEASETOOLS_EXTENSIONS := device/huawei/mt2

# RIL
BOARD_PROVIDES_LIBRIL := true
COMMON_GLOBAL_CFLAGS += -DUSE_RIL_VERSION_10
COMMON_GLOBAL_CPPFLAGS += -DUSE_RIL_VERSION_10
TARGET_RIL_VARIANT := caf

# SELinux
-include device/qcom/sepolicy/sepolicy.mk
BOARD_SEPOLICY_DIRS += device/huawei/mt2/sepolicy
BOARD_SEPOLICY_UNION += \
    libqmi_oem_main.te \
    oeminfo.te \
    platform_app.te

# TWRP
# TARGET_RECOVERY_DEVICE_MODULES += libQSEEComAPI.so
RECOVERY_GRAPHICS_USE_LINELENGTH := true
RECOVERY_SDCARD_ON_DATA := true
# RECOVERY_VARIANT := twrp
TW_BRIGHTNESS_PATH := "/sys/class/leds/lcd-backlight/brightness"
TW_EXTERNAL_STORAGE_MOUNT_POINT := "usb-otg"
TW_EXTERNAL_STORAGE_PATH := "/usb-otg"
TW_INCLUDE_CRYPTO := true
TW_THEME := portrait_hdpi

# Vold
BOARD_VOLD_MAX_PARTITIONS := 25
TARGET_USE_CUSTOM_LUN_FILE_PATH := /sys/devices/platform/msm_hsusb/gadget/lun%d/file

# Wifi
BOARD_HAS_QCOM_WLAN              := true
BOARD_HAS_QCOM_WLAN_SDK          := true
BOARD_HOSTAPD_DRIVER             := NL80211
BOARD_HOSTAPD_PRIVATE_LIB        := lib_driver_cmd_qcwcn
BOARD_WLAN_DEVICE                := qcwcn
BOARD_WPA_SUPPLICANT_DRIVER      := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_qcwcn
TARGET_PROVIDES_WCNSS_QMI        := true
TARGET_USES_QCOM_WCNSS_QMI       := true
TARGET_USES_WCNSS_MAC_ADDR_REV   := true
WIFI_DRIVER_FW_PATH_AP           := "ap"
WIFI_DRIVER_FW_PATH_STA          := "sta"
WPA_SUPPLICANT_VERSION           := VER_0_8_X

# inherit from the proprietary version
-include vendor/huawei/mt2/BoardConfigVendor.mk
