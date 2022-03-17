#include "settings_json_blob.h"

struct PalSettingsJsonBlob : public SettingsJsonBlob {
    const char* GetJsonBlob() override {
        static const char data[] = {'p', 'a', 'l', '\0'};
        return data;
    }
};

// Linker will drop this because this is built as static lib and is not
// referenced by any code linker is trying to link.
PalSettingsJsonBlob g_pal_settings_json_blob;
