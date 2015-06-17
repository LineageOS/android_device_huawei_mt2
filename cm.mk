# Copyright (C) 2014 The CyanogenMod Project
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

# Boot animation
TARGET_SCREEN_HEIGHT := 1280
TARGET_SCREEN_WIDTH := 720

$(call inherit-product, device/huawei/mt2/full_mt2.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Inherit device configuration
$(call inherit-product, device/huawei/mt2/mt2.mk)

PRODUCT_DEVICE := mt2
PRODUCT_NAME := cm_mt2

PRODUCT_BUILD_PROP_OVERRIDES += \
	PRODUCT_NAME=MT2L03 \
	BUILD_FINGERPRINT=Huawei/MT2L03/hwMT2L03:4.3/HuaweiMT2L03/C00B126:user/ota-rel-keys,release-keys \
	PRIVATE_BUILD_DESC="MT2-L03-user 4.3 GRJ90 C00B126 release-keys"
