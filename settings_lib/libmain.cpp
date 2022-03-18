#include "settings_json_blob.h"

SettingsJsonBlob* g_settings_json_blob_first = 0;
SettingsJsonBlob* g_settings_json_blob_last = 0;

API_EXPORT SettingsJsonBlob* GetSettingsJsonBlob() {
    return g_settings_json_blob_first;
}
