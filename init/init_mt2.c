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

#include <stdio.h>
#include <string.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "log.h"
#include "property_service.h"
#include "util.h"
#include "vendor_init.h"

#define APP_INFO "/proc/app_info"

/* Serial number */
#define SERIAL_PROP "ro.serialno"
#define REAL_SERIAL_PROP "usb.serial"

/* Bootmode */
#define HW_BOOTMODE_PROP "androidboot.huawei_bootmode"
#define BOOTMODE_PROP "ro.bootmode"

/* Bootloader version */
/* Example: MSM8926C00B309_BOOT */
#define BOOTLOADER_PROP "ro.bootloader"

static void import_kernel_nv(char *name, int for_emulator)
{
	prop_info *pi;
	int ret = 0;
	char bootmode[32] = { 0 };

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
	} else if (!strncmp(name, HW_BOOTMODE_PROP, 27)) {
		if (!strncmp(value, "hwcharger", 9))
			snprintf(bootmode, 8, "%s", "charger");
		else
			snprintf(bootmode, 32, "%s", value);

		pi = (prop_info*) __system_property_find(BOOTMODE_PROP);
		if (pi)
			ret = __system_property_update(pi, bootmode, strlen(bootmode));
		else
			ret = __system_property_add(BOOTMODE_PROP, strlen(BOOTMODE_PROP), bootmode, strlen(bootmode));
	}
}

static void get_bootloader_version()
{
	int ret = 0;
	char buf[128] = { 0 };
	char value[32] = { 0 };
	char *tok;
	prop_info *pi;

	FILE* f = fopen(APP_INFO, "rb");
	if (f == NULL) return;

	while (!feof(f)) {
		if (fgets(buf, 128, f) != NULL &&
				strstr(buf, "huawei_sbl1_version") != NULL) {
			tok = strchr(buf, ':');
			if (tok != NULL)
				tok = strtok(tok, ": ");
			if (tok != NULL) {
				snprintf(value, 32, "%s", tok);
				strtok(value, "\n");
			}
		}
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
