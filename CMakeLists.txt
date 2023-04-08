cmake_minimum_required(VERSION 3.26)

project(STATIC_LINKED_LIST_TEST LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(lib_foo)
add_subdirectory(shared_lib_bar)

add_executable(test main.cpp)

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
    target_link_libraries(App PRIVATE ${CMAKE_DL_LIBS})
endif()
