#pragma once

#include "Snake.h"
#include <iostream>

class Snake;
class Random;
class Food {
 public:
    Food(sf::RenderWindow *w, sf::Vector2f loc);
    ~Food() {
        std::cout << "Food\n";
    }

    sf::RectangleShape getFood();
    void drawFood();
    void changeLocation(sf::Vector2f newLocation);
    sf::Vector2f getNewPosition(std::deque<sf::RectangleShape>& snakeBody);
 private:
    Random rand;
    sf::Color color;
    sf::Vector2f location;
    sf::RectangleShape food;
    sf::RenderWindow *screen;
};
