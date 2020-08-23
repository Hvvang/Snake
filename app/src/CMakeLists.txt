cmake_minimum_required(VERSION 3.1)

include_directories(../../3dparty/sfml/include/)

set(SOURCES Game.cpp Snake.cpp Snake.h Random.cpp Random.h Utils.cpp Utils.h Food.cpp Food.h Menu.cpp LeaderBoards.cpp LeaderBoards.h)

add_library(src ${SOURCES})
target_link_libraries(src sfml-graphics sfml-window sfml-system)
