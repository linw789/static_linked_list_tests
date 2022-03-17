#include <settings_json_blob.h>

struct DxcpSettingsJsonBlob : public SettingsJsonBlob {
    const char* GetJsonBlob() override {
        static const char data[] = {'d', 'x', 'c', 'p', '\0'};
        return data;
    }
};

DxcpSettingsJsonBlob g_dxcp_settings_json_blob;
