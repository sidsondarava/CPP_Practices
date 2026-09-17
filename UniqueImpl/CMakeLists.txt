cmake_minimum_required(VERSION 3.15)

project(smart_pointers LANGUAGES CXX)

set(CMAKE_CXX_STANDERD 11)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-fno-elide-constructors)
endif()

add_executable(UniquePtr main.cpp)