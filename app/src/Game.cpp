#include "Game.h"

Game::Game(sf::RenderWindow *window, int width, int height) {
    this->InitVariables(width, height);
    this->window = window;
    this->player1 = new Snake(this->GetRenderWindow(), width / 2, height / 2);
    this->food = new Food(this->GetRenderWindow(), sf::Vector2f(120, 120));
}

Game::~Game() {
    delete this->player1;
    delete this->food;
}

void Game::InitVariables(int width, int height) {
    this->m_font.loadFromFile("ArialRegular.ttf");
    this->endGame = false;
    this->m_score = 0;

    this->m_scoreLabel.setFont(this->m_font);
    this->m_scoreLabel.setString("Score: " + std::to_string(m_score));
    this->m_scoreLabel.setPosition(sf::Vector2f(width - 200, 40));
}

bool Game::IsRunning() const {
    return this->window->isOpen();
}

void Game::PoolEvents() {
    while (this->window->pollEvent(this->windowEvent)) {
        switch (this->windowEvent.type) {
            case sf::Event::Closed:this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->windowEvent.key.code == sf::Keyboard::Escape)
                    this->window->close();
                else if (this->windowEvent.key.code == sf::Keyboard::Up) {
                    player1->changeMoveDirection(sf::Vector2<int>(0, -1));
                } else if (this->windowEvent.key.code == sf::Keyboard::Down) {
                    player1->changeMoveDirection(sf::Vector2<int>(0, 1));
                } else if (this->windowEvent.key.code == sf::Keyboard::Left) {
                    player1->changeMoveDirection(sf::Vector2<int>(-1, 0));
                } else if (this->windowEvent.key.code == sf::Keyboard::Right) {
                    player1->changeMoveDirection(sf::Vector2<int>(1, 0));
                } else if (this->windowEvent.key.code == sf::Keyboard::Space) {
                    player1->enlarger();
                }
                break;
        }
    }
}

void Game::update() {
    this->PoolEvents();
}

void Game::render() {
    this->window->clear();
    this->window->draw(m_scoreLabel);

    player1->moveSnake();
    player1->drawSnake();
    food->drawFood();

    sf::Time elapsed1 = m_clock.getElapsedTime();
    if (elapsed1.asSeconds() >= 4) {
        player1->enshorter();
        m_clock.restart();
    }
    if (CheckCollision(player1->getBody().front(), food->getFood())) {
        sf::Vector2f newLocation = food->getNewPosition(player1->getBody());
        m_score++;
        m_scoreLabel.setString("Score: " + std::to_string(m_score));
        food->changeLocation(newLocation);
        player1->enlarger();
        m_clock.restart();
    }
    if (player1->checkDeathCollision() || player1->getSnakeLength() < 2) {
        endGame = true;
    }
    int gameSpeed = 60 - player1->getSnakeLength();
    this->window->setFramerateLimit(gameSpeed <= 10 ? 10 : 10)   ;
    this->window->display();
}
void Game::SetPlayerOne(Snake *snake) {
    player1 = snake;
}

void Game::SetFood(Food *snakeFood) {
    food = snakeFood;
}

sf::RenderWindow *Game::GetRenderWindow() const {
    return this->window;
}
