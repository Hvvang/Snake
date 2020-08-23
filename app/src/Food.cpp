#include "Food.h"
#include "Utils.h"

Food::Food(sf::RenderWindow *w) {
    screen = w;
    color = sf::Color::Red;
}

sf::RectangleShape Food::getFood() {
    return food;
}

sf::Vector2f Food::getNewPosition(std::vector<sf::RectangleShape> &snakeBody) {
    bool collision = true;
    sf::Vector2f newLocation;

    while (collision) {
        int x = rand.getRandomInt(BOX_SIZE, screen->getSize().x - BOX_SIZE);
        int y = rand.getRandomInt(BOX_SIZE, screen->getSize().y - BOX_SIZE);

        newLocation.x = x;
        newLocation.y = y;
        collision = false;
        for (const auto& item : snakeBody) {
            if (item.getGlobalBounds().contains(newLocation)) {
                collision = true;
                break;
            }
        }
    }
    return newLocation;
}

void Food::drawFood() {
    food = getRectangleAt(location, color);
    screen->draw(food);
}

void Food::changeLocation(std::vector<sf::RectangleShape> &snakeBody) {
    location = Food::getNewPosition(snakeBody);
}
