#pragma once

#include <static_linked_list.h>

int foo1_compute_random(int n);

struct foo1_node : public static_linked_list
{
    const char* get_str() override;
};

extern foo1_node g_foo_node;
