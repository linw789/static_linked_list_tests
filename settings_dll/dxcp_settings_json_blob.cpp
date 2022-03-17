#include "settings_json_blob.h"

struct DxcpSettingsJsonBlob : public SettingsJsonBlob {
    DxcpSettingsJsonBlob() {
        this->next = 0;
        if (first == 0) {
            first = this;
            last = this;
        } else {
            last->next = this;
            last = this;
        }
    }

    const char* GetSettingsJsonBlob() override {
        static const char data[] = {'d', 'x', 'c', 'p'};
        return data;
    }
};

static DxcpSettingsJsonBlob g_dxcp_settings_json_blob;
