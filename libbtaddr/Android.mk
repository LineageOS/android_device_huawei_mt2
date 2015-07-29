LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
    libc \
    libcutils

LOCAL_SRC_FILES := \
    btaddr.c

LOCAL_MODULE := libbtaddr
LOCAL_MODULE_TAGS := optional
LOCAL_CFLAGS += -Wall

include $(BUILD_SHARED_LIBRARY)
