#pragma once

#include "pal_settings_json_blob.h"

extern PalSettingsJsonBlob g_pal_settings_json_blob;

void LinkAllPalSettings() {
    g_pal_settings_json_blob.LinkJsonBlob();
    // ... link other pal related settings blobs
}