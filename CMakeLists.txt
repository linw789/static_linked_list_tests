cmake_minimum_required(VERSION 3.26)

project(STATIC_LINKED_LIST_TEST LANGUAGES CXX)

add_subdirectory(static_linked_list)
add_subdirectory(lib_foo)
add_subdirectory(shared_lib_bar)

add_executable(test main.cpp)
target_compile_definitions(test PRIVATE BAR_PATH="${CMAKE_BINARY_DIR}/shared_lib_bar/Debug/shared_lib_bar.dll")

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
    target_link_libraries(App PRIVATE ${CMAKE_DL_LIBS})
endif()
