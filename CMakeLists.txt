cmake_minimum_required(VERSION 3.25)

project(STATIC_LINKED_LIST_TEST LANGUAGES CXX)

add_subdirectory(static_linked_list)
add_subdirectory(lib_foo)
add_subdirectory(shared_lib_bar)

add_executable(test main.cpp)

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    target_compile_definitions(test PRIVATE BAR_PATH="${CMAKE_BINARY_DIR}/shared_lib_bar/Debug/shared_lib_bar.dll")
elseif ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
    target_compile_definitions(test PRIVATE BAR_PATH="${CMAKE_BINARY_DIR}/shared_lib_bar/libshared_lib_bar.so")
    target_link_libraries(test ${CMAKE_DL_LIBS})
else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif()
