#include <iostream>
#include "Window.hpp"

void ValidateArgc(int argc) {
    if (argc != 3) {
        std::cerr << "usage: ./race00 [width] [height]" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    //ValidateArgc(argc);

    sf::Window window(sf::VideoMode(1920, 1080), "My window");

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}
