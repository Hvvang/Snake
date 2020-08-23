#include "Menu.h"
#include "Game.h"
#include "LeaderBoards.h"

Menu::Menu(sf::RenderWindow *window,
           float width,
           float height) : m_width(width), m_height(height), m_window(window)
    {
        if (!font.loadFromFile("ArialRegular.ttf"))
        {
            std::cerr << "Erorr" << std::endl;
        }
        menu[0].setCharacterSize(height / 20);
        menu[0].setFont(font);
        menu[0].setString("Write your name(by just typing text)!");
        menu[0].setPosition(sf::Vector2f(width / 2 - width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

        menu[1].setCharacterSize(height / 20);
        menu[1].setString("Your name: ");
        menu[1].setFont(font);
        menu[1].setPosition(sf::Vector2f(width / 2 - width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

        menu[2].setCharacterSize(height / 20);
        menu[2].setFont(font);
        menu[2].setString("Play");
        menu[2].setPosition(sf::Vector2f(width / 2 - width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

        menu[3].setCharacterSize(height / 20);
        menu[3].setFont(font);
        menu[3].setString("LeaderBoard");
        menu[3].setPosition(sf::Vector2f(width / 2 - width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

        menu[4].setCharacterSize(height / 20);
        menu[4].setFont(font);
        menu[4].setString("Exit");
        menu[4].setPosition(sf::Vector2f(width / 2 - width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

        selectedItemIndex = 2;
    }

Menu::~Menu() {
}

void Menu::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp() {
    if (selectedItemIndex - 1 >= 2) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown() {
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MenuLoop(sf::RenderWindow *window) {
    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            MoveUp();
                            break;
                        case sf::Keyboard::Down:
                            MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (GetPressedItem()) {
                                case 2:
                                    StartGame();
                                    break;
                                case 3:
                                    OpenLeaderBoard(m_window,
                                                    m_width,
                                                    m_height);
                                    break;
                                case 4:
                                    window->close();
                                    break;
                            }

                            break;
                    }
                    break;
                case sf::Event::TextEntered:
                    if (event.text.unicode < 128) {
                        m_username += event.text.unicode;
                        if (event.text.unicode == '\b')
                            m_username.erase(m_username.getSize() - 2, 2);
                        menu[1].setString("Your name: " + m_username);
                    }
                    break;
                case sf::Event::Closed:window->close();
                    break;

            }
        }
        window->clear();
        draw(*window);
        window->display();
    }
}

void Menu::StartGame() {
    Game game(m_window, m_width, m_height);
    while (game.IsRunning()) {
        // check all the window's events that were triggered since the last iteration of the loop

        if (!game.endGame) {
            game.update();
            game.render();
        } else {
            game.GetRenderWindow()->close();
        }
    }
}
void Menu::OpenLeaderBoard(sf::RenderWindow *window, int width, int height) {
    LeaderBoard lb(window, width, height);

    lb.LeaderBoardLoop();
}
