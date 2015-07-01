#include <string.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "log.h"
#include "property_service.h"
#include "util.h"
#include "vendor_init.h"

#define SERIAL_PROP "ro.serialno"
#define REAL_SERIAL_PROP "usb.serial"

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

void vendor_load_properties()
{
	import_kernel_cmdline(0, import_kernel_nv);
}
