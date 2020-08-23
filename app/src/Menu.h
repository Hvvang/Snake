#pragma once

#include "Snake.h"

#define MAX_NUMBER_OF_ITEMS 5

class Menu {
 public:
    Menu(sf::RenderWindow *window, float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    void MenuLoop(sf::RenderWindow *window);
    void StartGame();
    int GetPressedItem() const { return selectedItemIndex; }

 private:
    const int m_width, m_height;
    int selectedItemIndex;
    sf::Font font;
    sf::String m_username;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::RenderWindow *m_window;
    void OpenLeaderBoard(sf::RenderWindow *window, int width, int height);
};
