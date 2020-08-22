cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_EXTENSIONS OFF)
set(SFML_INCLUDE_DIR "./sfml/include")
set(SFML_LIBRARY_DIR "./sfml/build/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

find_package(SFML)
add_subdirectory(sfml)
