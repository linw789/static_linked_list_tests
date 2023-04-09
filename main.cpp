#ifdef _WIN32
    #include <windows.h>
#elif __GNUC__
    #include <dlfcn.h>
#endif

#include <stdio.h>

typedef void (*get_all_nodes_fn)(char* buf, size_t size);

int main(int argc, char** argv) {

    printf("BAR_PATH: %s\n", BAR_PATH);

    get_all_nodes_fn get_all_nodes = nullptr;

#ifdef _WIN32
    HMODULE bar_lib = LoadLibraryA(BAR_PATH);
    if (bar_lib == NULL) {
        printf("Failed to load DLL: %s\n.", argv[1]);
        return 1;
    }

    get_all_nodes = (get_all_nodes_fn)GetProcAddress(bar_lib, "get_all_nodes");

#elif __GNUC__
    void* settings_handle = dlopen(argv[1], RTLD_NOW);
    if (settings_handle == 0) {
        printf("Failed to load shared lib: %s. Because %s\n.", argv[1], dlerror());
    }
    get_int = (PFN_GetInt)dlsym(settings_handle, "GetInt");
    get_settings_jsob_blob = (PFN_GetSettingsJsonBlob)dlsym(settings_handle, "GetSettingsJsonBlob");
#endif

    if (get_all_nodes != 0) {
        char buf[1024] = {};
        get_all_nodes(buf, 1024);
        printf("all nodes: \n%s", buf);
    }

#ifdef _WIN32
    if (!FreeLibrary(bar_lib)) {
        printf("failed to free dll.");
    }
#elif __GNUC__
    if (dlclose(bar_lib) != 0) {
        printf("failed to close shared lib.");
    }
#endif

    return 0;
}