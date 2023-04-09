add_library(shared_lib_bar SHARED)
target_sources(shared_lib_bar PRIVATE
    bar.cpp
    bar.h
)
target_include_directories(shared_lib_bar PUBLIC ./)
target_link_libraries(shared_lib_bar
    PRIVATE
        static_linked_list
        lib_foo
)
