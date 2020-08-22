#pragma once

#include "Snake.h"

class Game {
 public:
    Game();
    ~Game();
    void update();
    void render();

    bool IsRunning() const;
    void PoolEvents();
    void SetPlayerOne(Snake *snake);
    sf::RenderWindow *GetRenderWindow() const;

    bool endGame;
 private:
    sf::VideoMode video_mode;
    sf::RenderWindow* window;
    sf::Event windowEvent;
    Snake *player1;

    void InitVariables();
    void InitWindow();
};
