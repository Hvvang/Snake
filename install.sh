#!/bin/zsh

install_sfml() {
    mkdir -p ./3dparty/sfml/build
    cd ./3dparty/sfml/build
    cmake ..
    make
}

install_sfml
