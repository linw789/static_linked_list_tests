#pragma once

#ifdef _WIN32
    #define API_EXPORT extern "C" __declspec(dllexport)
#elif __GNUC__
    #define API_EXPORT extern "C" __attribute__ ((visibility ("default")))
#endif

struct SettingsJsonBlob;

extern SettingsJsonBlob* g_settings_json_blob_first;
extern SettingsJsonBlob* g_settings_json_blob_last;

struct SettingsJsonBlob {
    SettingsJsonBlob* next;

    SettingsJsonBlob() {
        this->next = 0;
        if (g_settings_json_blob_first == 0) {
            g_settings_json_blob_first = this;
            g_settings_json_blob_last = this;
        } else {
            g_settings_json_blob_last->next = this;
            g_settings_json_blob_last = this;
        }
    }

    virtual const char* GetJsonBlob() {
        return 0;
    }
};
