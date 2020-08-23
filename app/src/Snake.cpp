#include "Snake.h"

Snake::Snake(sf::RenderWindow *w, int x, int y) {
    colorBody = sf::Color::Green;
    colorHead = sf::Color::Red;
    screen = w;
    currentMoveDirection = sf::Vector2<int>(0, -1);

    snakeLength = 4;
    for (int i = 0; i < 4; ++i) {
        if (i == 0)
            body.push_front(getRectangleAt(sf::Vector2f(x, y), colorHead));
        else
            body.push_back(getRectangleAt(body[i - 1].getPosition(), colorBody));
    }
}

void Snake::enlarger() {
    snakeLength++;
    updateLegth = true;
}

void Snake::drawSnake() {
    for (int i = 1; i < snakeLength; ++i) {
        screen->draw(body[i]);
    }
    screen->draw(body[0]);
}

void Snake::moveSnake() {
    sf::Vector2f newHead(body.front().getPosition().x
                             + (BOX_SIZE * currentMoveDirection.x),
                         body.front().getPosition().y
                             + (BOX_SIZE * currentMoveDirection.y));
    body.front().setFillColor(colorBody);
    body.push_front(getRectangleAt(newHead, colorHead));
    if (!updateLegth && (updateLegth = false))
        body.pop_back();
}

void Snake::changeMoveDirection(sf::Vector2<int> direction) {
    if ((currentMoveDirection.x == direction.x && currentMoveDirection.y != direction.y) ||
        (currentMoveDirection.x != direction.x && currentMoveDirection.y == direction.y))
        return;
    currentMoveDirection.x = direction.x;
    currentMoveDirection.y = direction.y;
}


std::vector<sf::RectangleShape>& Snake::getBody() {
    return body;

int Snake::getSnakeLength() {
    return snakeLength;
}

//void Snake::ateFood(Food *fd) {
//    if (checkCollision(body[0], fd->getFood())) {
//        delete fd;
//        enlarger();
//        return true;
//    }
//    return false;
//}
