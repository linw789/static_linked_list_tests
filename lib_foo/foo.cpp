#include "foo.h"

int foo_compute_random(int n)
{
    return n * n - 2;
}

const char* foo_node::get_str()
{
    return "foo";
}

foo_node g_foo_node;