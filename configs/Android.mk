# Copyright (C) 2015 The CyanogenMod Project
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

LOCAL_PATH:= $(call my-dir)

# GPS

# Cannot override gps.conf package,
# so PRODUCT_COPY_FILES instead

include $(CLEAR_VARS)
LOCAL_MODULE       := izat.conf
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_TAGS  := optional
LOCAL_SRC_FILES    := izat.conf
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := quipc.conf
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_TAGS  := optional
LOCAL_SRC_FILES    := quipc.conf
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := sap.conf
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_TAGS  := optional
LOCAL_SRC_FILES    := sap.conf
include $(BUILD_PREBUILT)

# IRSC

include $(CLEAR_VARS)
LOCAL_MODULE       := sec_config
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_TAGS  := optional
LOCAL_SRC_FILES    := sec_config
include $(BUILD_PREBUILT)

# Media

include $(CLEAR_VARS)
LOCAL_MODULE       := media_codecs.xml
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_TAGS  := optional
LOCAL_SRC_FILES    := media_codecs.xml
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := media_profiles.xml
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_TAGS  := optional
LOCAL_SRC_FILES    := media_profiles.xml
include $(BUILD_PREBUILT)

# Sensors

include $(CLEAR_VARS)
LOCAL_MODULE       := sensor_def_qcomdev.conf
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_TAGS  := optional
LOCAL_SRC_FILES    := sensor_def_qcomdev.conf
include $(BUILD_PREBUILT)

# Thermal

include $(CLEAR_VARS)
LOCAL_MODULE       := thermal-engine-8226.conf
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_TAGS  := optional
LOCAL_SRC_FILES    := thermal-engine-8226.conf
include $(BUILD_PREBUILT)
