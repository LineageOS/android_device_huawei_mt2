/*
** Copyright 2015, The CyanogenMod Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include <stdio.h>
#include <string.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "log.h"
#include "property_service.h"
#include "util.h"
#include "vendor_init.h"

#define SBL1_PART "/dev/block/platform/msm_sdcc.1/by-name/sbl1"

/* Serial number */
#define SERIAL_PROP "ro.serialno"
#define REAL_SERIAL_PROP "usb.serial"

/* Bootloader version */
/* Example: MSM8926C00B309_BOOT */
#define BOOTLOADER_PROP "ro.bootloader"
#define MSG_OFFSET 0x38DCC
#define MSG_LENGTH 20

static void import_kernel_nv(char *name, int for_emulator)
{
	prop_info *pi;
	int ret = 0;

	char *value = strchr(name, '=');
	if(!value)
		return;

	*value++ = 0;

	if(!strncmp(name, REAL_SERIAL_PROP, 10)) {
		pi = (prop_info*) __system_property_find(SERIAL_PROP);
		if(pi)
			ret = __system_property_update(pi, value, strlen(value));
		else
			ret = __system_property_add(SERIAL_PROP, strlen(SERIAL_PROP), value, strlen(value));
	}
}

static void get_bootloader_version()
{
	int ret = 0;
	char buf[MSG_LENGTH] = { 0 };
	char value[MSG_LENGTH] = { 0 };
	prop_info *pi;

	FILE* f = fopen(SBL1_PART, "rb");
	if (f == NULL) return;

	fseek(f, MSG_OFFSET, SEEK_SET);

	ret = fread(&buf, MSG_LENGTH, 1, f);
	if (ret == 1 && !strncmp("MSM8926", buf, 7)) {
		snprintf(value, MSG_LENGTH, "%s", buf);
	}

	fclose(f);

	if (strlen(value) > 0) {
		pi = (prop_info*) __system_property_find(BOOTLOADER_PROP);
		if(pi)
			ret = __system_property_update(pi, value,
					strlen(value));
		else
			ret = __system_property_add(BOOTLOADER_PROP,
					strlen(BOOTLOADER_PROP),
					value, strlen(value));
	}

}

void vendor_load_properties()
{
	import_kernel_cmdline(0, import_kernel_nv);
	get_bootloader_version();
}
