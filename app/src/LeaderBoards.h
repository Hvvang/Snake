#pragma once

#include "Game.h"
#include "Utils.h"
#include <map>
#include <string>

#define LEADERBOARD_ITEMS 12

class LeaderBoard {
 public:
    LeaderBoard(sf::RenderWindow *window, int width, int height);
    void LeaderBoardLoop();
    void draw();

 private:
    sf::RenderWindow *m_window;
    sf::Text menu[LEADERBOARD_ITEMS];
    sf::Font font;
    const int m_width, m_height;
    bool exit = false;
    std::multimap<int, std::string, bool (*)(int, int)> GetLeaders();
};
