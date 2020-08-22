#include "Utils.h"

sf::RectangleShape getRectangleAt( sf::Vector2f location, sf::Color color )
{
    sf::RectangleShape box;
    box.setSize(sf::Vector2f(40,40));
    box.setPosition(location);
    box.setFillColor(color);
    return box;

}

bool CheckCollision(const sf::RectangleShape& a, const sf::RectangleShape& b) {
    return a.getGlobalBounds().intersects( b.getGlobalBounds() );
}
