#pragma once

#include "Snake.h"
#include <iostream>

class Snake;
class Random;
class Food {
 public:
    Food(sf::RenderWindow *w);
    ~Food() {
        std::cout << "Food destructed\n";
    }

    sf::RectangleShape getFood();
    void drawFood();
    void changeLocation(std::vector<sf::RectangleShape> &snakeBody);
 private:
    Random rand;
    sf::Color color;
    sf::Vector2f location;
    sf::RectangleShape food;
    sf::RenderWindow *screen;
    sf::Vector2f getNewPosition(std::vector<sf::RectangleShape> &snakeBody);
};
