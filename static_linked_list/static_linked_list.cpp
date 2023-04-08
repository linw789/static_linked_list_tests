#include "static_linked_list.h"

#define ASSERT(cond) if (cond) {} else { *(int*)0 = 0; }

static_linked_list* g_first_node = nullptr;
static_linked_list* g_last_node = nullptr;

static_linked_list::static_linked_list()
{
    this->next = nullptr;
    if (g_first_node == nullptr) {
        ASSERT(g_last_node == nullptr);
        g_first_node = this;
        g_last_node = this;
    } else {
        g_last_node->next = this;
        g_last_node = this;
    }
}
