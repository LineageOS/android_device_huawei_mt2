/*
 * Copyright (C) 2015 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "libwcnss_qmi"
#include <cutils/log.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define OEMINFO_PART "/dev/block/platform/msm_sdcc.1/by-name/oeminfo"

#define BT_MAC_OFFSET 0x32200
#define WIFI_MAC_OFFSET 0x1F4

#define MAC_SIZE 6
#define MAC_ADDRESS_STR "%02x:%02x:%02x:%02x:%02x:%02x"
#define MAC_ADDR_ARRAY(a) (a)[5], (a)[4], (a)[3], (a)[2], (a)[1], (a)[0]

int wcnss_init_qmi(void)
{
    int ret = access(OEMINFO_PART, R_OK);
    if(ret)
        ALOGE("Cannot access oeminfo partition: %s", strerror(errno));

    return ret;
}

void wcnss_qmi_deinit(void)
{
}

int wcnss_qmi_get_wlan_address(unsigned char *wlan_mac)
{
    uint64_t bt_mac = 0;
    int i, fd, ret = -1;

    fd = open(OEMINFO_PART, O_RDONLY);
    if(fd < 0) {
        ALOGE("Cannot open oeminfo partition: %s", strerror(errno));
        goto out;
    }

    if(lseek(fd, BT_MAC_OFFSET, SEEK_SET) != BT_MAC_OFFSET) {
        ALOGE("Cannot seek to MAC address location: %s", strerror(errno));
        goto err;
    }

    if(read(fd, &bt_mac, MAC_SIZE) < 0) {
        ALOGE("Cannot read MAC address: %s", strerror(errno));
        goto err;
    }

    ALOGD("Found Bluetooth MAC: " MAC_ADDRESS_STR, MAC_ADDR_ARRAY((unsigned char*)&bt_mac));

    bt_mac += WIFI_MAC_OFFSET;
    for(i = 0; i < MAC_SIZE; i++)
        wlan_mac[i] = (unsigned char)(bt_mac >> ((MAC_SIZE - i - 1) * 8));

    ret = 0;
err:
    close(fd);
out:
    return ret;
}
