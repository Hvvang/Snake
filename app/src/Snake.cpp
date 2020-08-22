#include "Snake.h"

Snake::Snake(sf::RenderWindow *w, int x, int y) {
    colorBody = sf::Color::Green;
    colorHead = sf::Color::Red;
    movementSpeed = 5;
    screen = w;

    snakeLength = 1;

    for (int i = 0; i < 4; ++i) {
        if (i == 0) {
            body.push_back(getRectangleAt(sf::Vector2f(x, y), colorHead));
            snakeMoveList.push_front(sf::Vector2<int>(-1, 0));
        }
        else
            enlarger();
    }
}

void Snake::enlarger() {
    sf::Vector2f new_location = body[snakeLength - 1].getPosition();
    body.push_back(getRectangleAt(new_location, colorBody));
    snakeMoveList.push_back(lastDirection);
    snakeLength++;
}

void Snake::drawSnake() {
    for (int i = 1; i < snakeLength; ++i) {
        screen->draw( body[i]);
    }
    screen->draw( body[0] );
}

void Snake::moveSnake() {
    snakeMoveList.push_front(currentMoveDirection);
    lastDirection = snakeMoveList.back();
    snakeMoveList.pop_back();

    int index = 0;
    for (auto i = snakeMoveList.begin();
         i != snakeMoveList.end() && index < snakeLength; i++, index++) {
        body[index].move(movementSpeed * (*i).x, movementSpeed * (*i).y);
    }
}

void Snake::changeMoveDirection(sf::Vector2<int> direction) {
    currentMoveDirection.x = direction.x;
    currentMoveDirection.y = direction.y;
}

//void Snake::ateFood(Food *fd) {
//    if (checkCollision(body[0], fd->getFood())) {
//        delete fd;
//        enlarger();
//        return true;
//    }
//    return false;
//}
