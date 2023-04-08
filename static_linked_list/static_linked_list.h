#pragma once

struct static_linked_list;

extern static_linked_list* g_first_node;
extern static_linked_list* g_last_node;

struct static_linked_list
{
    static_linked_list* next;
    int value;

    static_linked_list();
    virtual const char* get_str() = 0;
};
