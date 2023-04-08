#pragma once

#include <static_linked_list.h>
#include <foo.h>

#ifdef _WIN32
    #define API_EXPORT extern "C" __declspec(dllexport)
#elif __GNUC__
    #define API_EXPORT extern "C" __attribute__ ((visibility ("default")))
#endif

int bar_beep(int r);

struct bar_node : public static_linked_list
{
    const char* get_str() override;
};

extern bar_node g_bar_node;

API_EXPORT void get_all_nodes(char* buf, size_t size);
