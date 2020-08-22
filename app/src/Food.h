#pragma once

#include "Snake.h"
#include <iostream>

class Food {
 public:
    Food(sf::RenderWindow *, sf::Vector2f loc);
    sf::RectangleShape getFood();
    void drawFood();
    ~Food() {
        std::cout << "Food\n";
    }
 private:
    sf::Color color;
    sf::Vector2f location;
    sf::RectangleShape food;
    sf::RenderWindow *screen;
};
