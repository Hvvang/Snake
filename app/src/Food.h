#pragma once

#include "Snake.h"
#include <iostream>

class Food {
 public:
    Food(sf::RenderWindow *w, sf::Vector2f loc);
    ~Food() {
        std::cout << "Food\n";
    }

    sf::RectangleShape getFood();
    void drawFood();
    void changeLocation(sf::Vector2f newLocation);

 private:
    sf::Color color;
    sf::Vector2f location;
    sf::RectangleShape food;
    sf::RenderWindow *screen;
};
