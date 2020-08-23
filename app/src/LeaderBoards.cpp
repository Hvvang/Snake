#include "LeaderBoards.h"

bool cmp(int lhs, int rhs) {return lhs > rhs;}

std::multimap<int, std::string, bool (*)(int, int)> LeaderBoard::GetLeaders() {
    std::multimap<int, std::string, bool(*)(int,int)> test(cmp);
    std::ifstream inp(".leaderboards");
    std::string line;

    while (std::getline(inp, line)) {
        if (line.size() != 0) {
            unsigned long position = line.find(' ');
            std::string score(line.begin() + position, line.end());
            std::string name(line.begin(), line.begin() + position);
            test.insert(std::make_pair(std::stoi(score), name));
        }
    }
    return test;
}

LeaderBoard::LeaderBoard(sf::RenderWindow *window, int width, int height)
    : m_window(window), m_width(width), m_height(height) {
    std::multimap<int, std::string, bool(*)(int,int)> leaders = GetLeaders();
    int index = 2;

    font.loadFromFile("ArialRegular.ttf");

    menu[0].setCharacterSize(height / 20);
    menu[0].setFont(font);
    menu[0].setString("Leaderboard!");
    menu[0].setPosition(sf::Vector2f(m_width / 2 - 50, m_height / (LEADERBOARD_ITEMS + 1) * 1));

    menu[1].setCharacterSize(height / 20);
    menu[1].setFont(font);
    menu[1].setString("Press Escape to return!");
    menu[1].setPosition(sf::Vector2f(m_width - m_width + 100, m_height - m_height + 100));
    for (const auto &leader : leaders) {
        if (index >= 12)
            break;
        menu[index].setCharacterSize(height / 20);
        menu[index].setFont(font);
        menu[index].setString(std::to_string(index - 1) + ". " + leader.second + ": " + std::to_string(leader.first));
        menu[index].setPosition(sf::Vector2f(m_width / 2 - 50, m_height / (LEADERBOARD_ITEMS + 1) * (index + 1)));
        index++;
    }
}

void LeaderBoard::draw() {
    for (int i = 0; i < LEADERBOARD_ITEMS; ++i) {
        m_window->draw(menu[i]);
    }
}

void LeaderBoard::LeaderBoardLoop() {
    sf::Event event;

    while (!m_window->pollEvent(event) && !exit) {
        switch (event.type) {
            case sf::Event::Closed:
                this->m_window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    exit = true;
                break;
        }
        m_window->clear();
        draw();
        m_window->display();
    }
}
