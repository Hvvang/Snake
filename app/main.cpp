#include <iostream>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include "src/Game.h"
#include "src/Menu.h"

void ValidateArgc(int argc, char** argv, int& width, int& height) {
    if (argc != 3) {
        std::cerr << "usage: ./race00 [width] [height]" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        size_t index = 0;
        try {
            width = std::stoi(argv[1], &index);
            if (argv[1][index] != '\0') throw false;
            height = std::stoi(argv[2], &index);
            if (argv[2][index] != '\0') throw false;
        }
        catch (...) {
            std::cerr << "Invalid arguments" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char *argv[]) {
    int width = 0;
    int height = 0;
    ValidateArgc(argc, argv, width, height);
    if (width > sf::VideoMode::getDesktopMode().width || width < 720 ||
        height > sf::VideoMode::getDesktopMode().height || height < 480) {
        std::cerr << "Use width=(720; " << sf::VideoMode::getDesktopMode().width << ") ";
        std::cerr << "height=(480; " << sf::VideoMode::getDesktopMode().height << ")\n";
        exit(EXIT_FAILURE);
    }
    sf::VideoMode mode = sf::VideoMode(width, height);
    sf::RenderWindow *window = new sf::RenderWindow(mode,
                                                    "Race00",
                                                    sf::Style::Close | sf::Style::Titlebar);
    Menu menu(window, width, height);
    menu.MenuLoop(window);
    return 0;
}
