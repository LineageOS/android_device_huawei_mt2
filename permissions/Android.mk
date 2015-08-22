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

include $(CLEAR_VARS)
LOCAL_MODULE       := com.qualcomm.location.xml
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH  := $(TARGET_OUT_ETC)/permissions
LOCAL_MODULE_TAGS  := optional
LOCAL_SRC_FILES    := com.qualcomm.location.xml
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := qcnvitems.xml
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH  := $(TARGET_OUT_ETC)/permissions
LOCAL_MODULE_TAGS  := optional
LOCAL_SRC_FILES    := qcnvitems.xml
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := qcrilhook.xml
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH  := $(TARGET_OUT_ETC)/permissions
LOCAL_MODULE_TAGS  := optional
LOCAL_SRC_FILES    := qcrilhook.xml
include $(BUILD_PREBUILT)
