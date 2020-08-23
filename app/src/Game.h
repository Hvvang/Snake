#pragma once

#include "Snake.h"
#include "Food.h"

class Food;
class Game {
 public:
    Game(sf::RenderWindow *window, int width, int height);
    ~Game();
    void update();
    void render();

    bool IsRunning() const;
    void PoolEvents();
    void SetPlayerOne(Snake *snake);
    void SetFood(Food *food);
    sf::RenderWindow *GetRenderWindow() const;

    bool endGame;
 private:
    sf::RenderWindow *window;
    sf::Event windowEvent;
    Snake *player1;
    Food *food;
    sf::Clock m_clock;
    sf::Font m_font;
    sf::Text m_scoreLabel;
    int m_score;

    void InitVariables(int width, int height);
};
