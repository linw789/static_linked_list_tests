#include <stdio.h>
#include <errno.h>

#ifdef _WIN32
    #include <windows.h>
#elif __GNUC__
    #include <dlfcn.h>
    #include <string.h>
#endif

typedef void (*get_all_nodes_fn)(char* buf, size_t size);

int main(int argc, char** argv) {

    printf("BAR_PATH: %s\n", BAR_PATH);

    get_all_nodes_fn get_all_nodes = nullptr;

#ifdef _WIN32
    HMODULE bar_lib = LoadLibraryA(BAR_PATH);
    if (bar_lib == NULL) {
        printf("Failed to load DLL: %s\n.", BAR_PATH);
        return 1;
    }

    get_all_nodes = (get_all_nodes_fn)GetProcAddress(bar_lib, "get_all_nodes");
    if (get_all_nodes == NULL) {
        printf("Failed to function pointer 'get_all_nodes'.\n");
        return 1;
    }

#elif __GNUC__
    void* bar_lib = dlopen(BAR_PATH, RTLD_NOW);
    if (bar_lib == 0) {
        printf("Failed to load shared lib. Error: %s\n.", dlerror());
    }
    get_all_nodes = (get_all_nodes_fn)dlsym(bar_lib, "get_all_nodes");
    if (get_all_nodes == NULL) {
        printf("Failed to function pointer 'get_all_nodes'. Error: %s\n.", dlerror());
        return 1;
    }
#endif

    char buf[1024] = {};
    get_all_nodes(buf, 1024);
    printf("all nodes: \n%s", buf);

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