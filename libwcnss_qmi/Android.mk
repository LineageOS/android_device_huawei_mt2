ifeq ($(TARGET_PROVIDES_WCNSS_QMI),true)

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
    libc \
    libcutils \
    liblog

LOCAL_SRC_FILES := \
    wcnss_qmi.c

LOCAL_MODULE := libwcnss_qmi
LOCAL_MODULE_TAGS := optional
LOCAL_CFLAGS += -Wall

include $(BUILD_SHARED_LIBRARY)

endif
