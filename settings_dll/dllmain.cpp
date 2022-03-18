#include "dxcp_settings_json_blob.h"
#include <settings_json_blob.h>
#include <all_pal_related_settings_json_blobs.h>

API_EXPORT int GetInt() {
    return 17;
}
extern SettingsJsonBlob* g_settings_json_blob_first;
extern DxcpSettingsJsonBlob g_dxcp_settings_json_blob;

API_EXPORT SettingsJsonBlob* GetSettingsJsonBlob() {
    g_dxcp_settings_json_blob.LinkJsonBlob();
    LinkAllPalSettings();
    return g_settings_json_blob_first;
}