add_library(foo STATIC)
target_sources(foo PRIVATE
    foo.cpp
    foo.h
)
target_include_directories(foo PUBLIC ./)
