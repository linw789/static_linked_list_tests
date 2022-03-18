#pragma once

#include "settings_json_blob.h"

struct PalSettingsJsonBlob : public SettingsJsonBlob {
    const char* GetJsonBlob() override {
        static const char data[] = {'p', 'a', 'l', '\0'};
        return data;
    }
};
