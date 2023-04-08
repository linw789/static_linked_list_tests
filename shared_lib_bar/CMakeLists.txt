add_library(foo SHARED)
target_sources(foo PRIVATE
    bar.cpp
    bar.h
)
target_include_directories(bar PUBLIC ./)
target_link_libraries(bar PRIVATE static_linked_list)
