#ifdef _WIN32
    #include <windows.h>
#endif

#include <stdio.h>
#include <settings_json_blob.h>

typedef SettingsJsonBlob* (*PFN_GetSettingsJsonBlob)();
typedef int (*PFN_GetInt)();

int main(int argc, char** argv) {

#ifdef _WIN32
    HMODULE settings_handle = LoadLibraryA(argv[1]);
    if (settings_handle == NULL) {
        printf("Failed to load DLL.");
        return 1;
    }

    PFN_GetInt get_int = (PFN_GetInt)GetProcAddress(settings_handle, "GetInt");
    printf("GetInt: %d\n", get_int());

    PFN_GetSettingsJsonBlob get_settings_jsob_blob =
        (PFN_GetSettingsJsonBlob)GetProcAddress(settings_handle, "GetSettingsJsonBlob");

    SettingsJsonBlob* json_blob = get_settings_jsob_blob();
    while (json_blob != 0) {
        const char* blob = json_blob->GetJsonBlob();
        printf("json blob: %s\n", blob);
        json_blob = json_blob->next;
    }

    if (!FreeLibrary(settings_handle)) {
        printf("failed to free dll.");
    }
#endif

    return 0;
}