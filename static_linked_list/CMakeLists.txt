add_library(static_linked_list STATIC)
target_sources(static_linked_list PRIVATE
    static_linked_list.cpp
    static_linked_list.h
)
target_include_directories(static_linked_list PUBLIC ./)
