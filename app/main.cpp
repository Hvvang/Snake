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
    ValidateArgc(argc);
    int width = std::stoi(argv[1]);
    int height = std::stoi(argv[2]);
    Game game(width, height);

    game.SetPlayerOne(new Snake(game.GetRenderWindow(), width / 2, height / 2));

    while (game.IsRunning())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        game.update();
        game.render();
    }
    return 0;
}
