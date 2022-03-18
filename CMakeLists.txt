cmake_minimum_required(VERSION 3.13)

project(DllStaticInit LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(settings_lib)
add_subdirectory(settings_dll)

add_executable(App main.cpp)

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
    target_link_libraries(App PRIVATE ${CMAKE_DL_LIBS})
endif()
