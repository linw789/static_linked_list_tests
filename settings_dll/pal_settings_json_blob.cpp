#include "settings_json_blob.h"

struct PalSettingsJsonBlob : public SettingsJsonBlob {
    PalSettingsJsonBlob() {
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
        static const char data[] = {'p', 'a', 'l'};
        return data;
    }
};

static PalSettingsJsonBlob g_pal_settings_json_blob;
