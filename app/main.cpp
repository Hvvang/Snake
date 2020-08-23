#include <iostream>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include "src/Game.h"
#include "src/Menu.h"

void ValidateArgc(int argc) {
    if (argc != 3) {
        std::cerr << "usage: ./race00 [width] [height]" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    ValidateArgc(argc);
    int width = std::stoi(argv[1]);
    int height = std::stoi(argv[2]);
    sf::VideoMode mode = sf::VideoMode(width, height);
    sf::RenderWindow *window = new sf::RenderWindow(mode,
                                                    "Race00",
                                                    sf::Style::Close | sf::Style::Titlebar);
    Menu menu(window, width, height);

    menu.MenuLoop(window);
    return 0;
}
