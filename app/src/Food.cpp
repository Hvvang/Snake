#include "Food.h"
#include "Utils.h"

Food::Food(sf::RenderWindow *w, sf::Vector2f loc) {
    location = loc;
    screen = w;
    color = sf::Color::Red;
    food = getRectangleAt(location, color);

}

sf::RectangleShape Food::getFood() {
    return food;
}

void Food::drawFood() {
    screen->draw(food);
}
