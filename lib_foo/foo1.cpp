#include "foo1.h"

int foo1_compute_random(int n)
{
    return n * n - 4;
}

const char* foo1_node::get_str()
{
    return "foo1";
}

foo1_node g_foo_node;
