#pragma once

#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <deque>

#include "Random.h"
#include "Food.h"
#include "Utils.h"

#define BOX_SIZE 40

class Food;
class Snake {
 public:
    Snake(sf::RenderWindow *w, int x, int y);
    void drawSnake();
    void died();
    void ateFood(Food *fd);
    void changeMoveDirection(sf::Vector2<int> direction);
    void moveSnake();
    std::deque<sf::RectangleShape>& getBody();
    void enlarger();
    int getSnakeLength();
    bool checkDeathCollision();

 private:
    sf::RenderWindow *screen;
    Random rand;

    /* Used to determine whether or not to increment length of snake */
    bool updateLegth;

    /* The rate of movement of snake */
    float movementSpeed;

    /* Snake parameters */
    int snakeLength;
    sf::Vector2<int> currentMoveDirection;
    std::vector<sf::RectangleShape> body;

    /* Load from options */
    sf::Color colorBody;
    sf::Color colorHead;
};
