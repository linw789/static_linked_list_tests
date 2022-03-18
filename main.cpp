#ifdef _WIN32
    #include <windows.h>
#elif __GNUC__
    #include <dlfcn.h>
#endif

#include <stdio.h>
#include "settings_lib/settings_json_blob.h"

typedef SettingsJsonBlob* (*PFN_GetSettingsJsonBlob)();
typedef int (*PFN_GetInt)();

int main(int argc, char** argv) {

    PFN_GetInt get_int = 0;
    PFN_GetSettingsJsonBlob get_settings_jsob_blob = 0;

#ifdef _WIN32
    HMODULE settings_handle = LoadLibraryA(argv[1]);
    if (settings_handle == NULL) {
        printf("Failed to load DLL: %s\n.", argv[1]);
        return 1;
    }

    get_int = (PFN_GetInt)GetProcAddress(settings_handle, "GetInt");

    get_settings_jsob_blob = (PFN_GetSettingsJsonBlob)GetProcAddress(settings_handle, "GetSettingsJsonBlob");

#elif __GNUC__
    void* settings_handle = dlopen(argv[1], RTLD_NOW);
    if (settings_handle == 0) {
        printf("Failed to load shared lib: %s. Because %s\n.", argv[1], dlerror());
    }
    get_int = (PFN_GetInt)dlsym(settings_handle, "GetInt");
    get_settings_jsob_blob = (PFN_GetSettingsJsonBlob)dlsym(settings_handle, "GetSettingsJsonBlob");
#endif

    if (get_int != 0) {
        printf("GetInt: %d\n", get_int());
    }

    if (get_settings_jsob_blob != 0) {
        SettingsJsonBlob* json_blob = get_settings_jsob_blob();
        while (json_blob != 0) {
            const char* blob = json_blob->GetJsonBlob();
            printf("json blob: %s\n", blob);
            json_blob = json_blob->next;
        }
    }

#ifdef _WIN32
    if (!FreeLibrary(settings_handle)) {
        printf("failed to free dll.");
    }
#elif __GNUC__
    if (dlclose(settings_handle) != 0) {
        printf("failed to close shared lib.");
    }
#endif

    return 0;
}