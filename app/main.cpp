#include <iostream>
#include "Window.hpp"

int main(int argc, char *argv[]) {
    sf::Window window(sf::VideoMode(1280, 720), "My window");

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
