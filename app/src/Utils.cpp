#include "Utils.h"

sf::RectangleShape getRectangleAt(sf::Vector2f location, sf::Color color) {
    sf::RectangleShape box;
    box.setSize(sf::Vector2f(BOX_SIZE, BOX_SIZE));
    box.setPosition(location);
    box.setOutlineThickness(3);
    box.setFillColor(color);
    return box;

}

bool CheckCollision(const sf::RectangleShape &a, const sf::RectangleShape &b) {
    sf::Rect<float> c(a.getGlobalBounds().left,
                      a.getGlobalBounds().top,
                      a.getGlobalBounds().width - 1,
                      a.getGlobalBounds().height - 1);
    sf::Rect<float> d(b.getGlobalBounds().left,
                      b.getGlobalBounds().top,
                      b.getGlobalBounds().width - 1,
                      b.getGlobalBounds().height - 1);
    return c.intersects(d);
}

void SaveResultToFile(std::string username, int score) {
    std::vector<std::string> file;
    std::ifstream inp(".leaderboards");
    std::string line;

    if (username.empty())
        return;

    while (std::getline(inp, line)) {
        if (line.size() != 0) {
            file.push_back(line);
        }
    }
    int index = 0;
    bool finded = false;
    for (auto iter = file.begin(); iter != file.end(); ++iter, index++) {
        try {
            unsigned long position = iter->find(' ');
            if (std::string(iter->begin(), iter->begin() + position)
                == username) {
                if (std::stoi(std::string(iter->begin() + position + 1,
                                          iter->end())) < score)
                    file[index] =
                        std::string(username + " " + std::to_string(score));
                finded = true;
            }
        }
        catch (...) {}
    }
    if (!finded)
        file.push_back(std::string(username + " " + std::to_string(score)));
    std::ofstream
        out(".leaderboards", std::ofstream::out | std::ofstream::trunc);
    for (const auto &str : file) {
        out << str << std::endl;
    }
    out.close();
    inp.close();
}
