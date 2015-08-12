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

#define LOG_TAG "libbtaddr"

#include <ctype.h>
#include <cutils/log.h>
#include <cutils/properties.h>
#include <stdio.h>

#define SERIAL_PROP "ro.serialno"
#define MAC_STR_LEN 12

int BT_BDAddrGet(unsigned char *bluetooth_mac)
{
    char btaddr[PROP_VALUE_MAX] = { 0 };
    int i;

    if (property_get(SERIAL_PROP, btaddr, NULL) != MAC_STR_LEN) {
        ALOGE("Failed to read BT MAC; %s does not contain MAC address", SERIAL_PROP);
        return -1;
    }

    for (i = 0; i < MAC_STR_LEN; i++) {
        if (!isxdigit(btaddr[i])) {
            ALOGE("Failed to read BT MAC; %s contains non-hex character(s)", SERIAL_PROP);
            return -1;
        }
    }

    sscanf(btaddr, "%02hhx%02hhx%02hhx%02hhx%02hhx%02hhx",
            &bluetooth_mac[0],
            &bluetooth_mac[1],
            &bluetooth_mac[2],
            &bluetooth_mac[3],
            &bluetooth_mac[4],
            &bluetooth_mac[5]);

    ALOGD("Found Bluetooth MAC: %02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx",
            bluetooth_mac[0],
            bluetooth_mac[1],
            bluetooth_mac[2],
            bluetooth_mac[3],
            bluetooth_mac[4],
            bluetooth_mac[5]);

    return 0;
}
