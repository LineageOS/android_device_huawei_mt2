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

#define LOG_TAG "app_info"

#include <cutils/log.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define APP_INFO "/proc/app_info"

int get_app_info(char* key, char* value) {
    char buf[128] = { 0 };
    char *tok;
    FILE* f;

    ALOGI("Getting App Info for %s", key);

    if(key == NULL) {
        ALOGE("Key is null");
        return -1;
    }

    f = fopen(APP_INFO, "rb");
    if(f == NULL) {
        ALOGE("Failed to open %s: %s", APP_INFO, strerror(errno));
        return -2;
    }

    while (!feof(f)) {
        if (fgets(buf, 128, f) != NULL &&
                strstr(buf, key) != NULL) {
            tok = strchr(buf, ':');
            if (tok != NULL)
                tok = strtok(tok, ": ");
            if (tok != NULL) {
                snprintf(value, 33, "%s", tok);
                strtok(value, "\n");
            }
            break;
        }
    }

    fclose(f);

    ALOGI("%s=%s", key, value);

    return 0;
}
