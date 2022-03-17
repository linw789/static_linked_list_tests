#include "settings_json_blob.h"

SettingsJsonBlob* SettingsJsonBlob::first;
SettingsJsonBlob* SettingsJsonBlob::last;

__declspec(dllexport) SettingsJsonBlob* __cdecl GetSettingsJsonBlob() {
    return SettingsJsonBlob::first;
}
