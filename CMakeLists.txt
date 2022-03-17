cmake_minimum_required(VERSION 3.20)

project(Cpp_Experiments)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(settings_dll)

add_executable(App main.cpp)
