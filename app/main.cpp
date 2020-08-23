#include <iostream>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include "src/Game.h"

void ValidateArgc(int argc) {
    if (argc != 3) {
        std::cerr << "usage: ./race00 [width] [height]" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    //ValidateArgc(argc);
    Game game;
    Food *food = new Food(game.GetRenderWindow(), sf::Vector2f(10, 10));
    game.SetPlayerOne(new Snake(game.GetRenderWindow(), 200, 200));
    game.SetFood(food);
    while (game.IsRunning())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        game.update();
        game.render();
    }
    return 0;
}
