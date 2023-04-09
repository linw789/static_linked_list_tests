#include "bar.h"
#include "foo.h"
#include <string.h>

#define ASSERT(cond) if (cond) {} else { *(int*)0 = 0; }

int bar_beep(int r)
{
    return (r + 3) * r;
}

const char* bar_node::get_str()
{
    return "bar";
}

bar_node g_bar_node;

void get_all_nodes(char* buf, size_t size)
{
    // Here we reference a symbol from foo.cpp, so foo_node should be imported
    // in bar.dll. But we also want to find out if foo1_node will imported in
    // bar.dll.
    int rand = foo_compute_random(13);

    size_t buf_pos = 0;
    static_linked_list* node = g_first_node;
    while (node != nullptr)
    {
        const char* str = node->get_str();
        size_t str_size = strlen(str);
        memcpy(buf + buf_pos, str, str_size);
        buf_pos += str_size;
        ASSERT(buf_pos < size);
        *(buf + buf_pos) = '\n';
        buf_pos += 1;
        ASSERT(buf_pos < size);

        node = node->next;
    }
    *(buf + buf_pos) = '\0';
}
