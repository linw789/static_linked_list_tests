#pragma once

#include <static_linked_list.h>

int foo_compute_random(int n);

struct foo_node : public static_linked_list
{
    const char* get_str() override;
};

extern foo_node* g_foo_node;
