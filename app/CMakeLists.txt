cmake_minimum_required(VERSION 3.1)

project(race00 LANGUAGES CXX)
set(SOURCE_EXE main.cpp)
add_subdirectory(src)

include_directories(../3dparty/sfml/include/)

add_compile_options(
        -std=c++17
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
)

add_executable(race00 ${SOURCE_EXE})
target_link_libraries(race00 sfml-graphics sfml-window sfml-system src)
include_directories(race00 ${SFML_INCLUDE_DIR})
