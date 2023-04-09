add_library(lib_foo STATIC)
target_sources(lib_foo PRIVATE
    foo.cpp
    foo.h
    foo1.cpp
    foo1.h
)
target_include_directories(lib_foo PUBLIC ./)
target_link_libraries(lib_foo PRIVATE static_linked_list)
