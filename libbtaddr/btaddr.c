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
