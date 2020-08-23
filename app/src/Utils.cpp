#include "Utils.h"

sf::RectangleShape getRectangleAt( sf::Vector2f location, sf::Color color )
{
    sf::RectangleShape box;
    box.setSize(sf::Vector2f(BOX_SIZE, BOX_SIZE));
    box.setPosition(location);
    box.setOutlineThickness(3);
    box.setFillColor(color);
    return box;

}

bool CheckCollision(const sf::RectangleShape& a, const sf::RectangleShape& b) {
    sf::Rect<float> c(a.getGlobalBounds().left, a.getGlobalBounds().top, a.getGlobalBounds().width - 1, a.getGlobalBounds().height - 1);
    sf::Rect<float> d(b.getGlobalBounds().left, b.getGlobalBounds().top, b.getGlobalBounds().width - 1, b.getGlobalBounds().height - 1);
    // std::cout << d.height << std::endl;
    return c.intersects(d);
}

void SaveResultToFile(std::string& username, int score) {
    std::vector<std::string> file;
    std::ifstream inp(".leaderboards");
    std::string line;

    while (std::getline(inp, line)) {
        if (line.size() != 0) {
            file.push_back(line);
        }
    }
    int index = 0;
    for (auto iter = file.begin(); iter != file.end(); ++iter) {
        unsigned long position = iter->find(' ');
        std::string user;
        if (std::string(iter->begin(), iter->begin() + position) == username) {
            if (std::string(iter->begin() + position, iter->end()) == std::to_string(score))
                file[index] = username + " " + std::to_string(score);
        }
        index++;
    }
    std::ofstream out(".leaderboards", std::ofstream::out | std::ofstream::trunc);
    for (const auto &str : file) {
        out << str << std::endl;
    }
    out.close();
    inp.close();
}
