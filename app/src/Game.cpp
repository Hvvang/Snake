#include "Game.h"

Game::Game(int width, int height) {
    this->InitVariables();
    this->InitWindow(width, height);
}

Game::~Game() {
    delete this->window;
    delete this->player1;
}

void Game::InitVariables() {
    this->endGame = false;
}

void Game::InitWindow(int width, int height) {
    this->video_mode = sf::VideoMode(width, height);
    this->window = new sf::RenderWindow(this->video_mode,
                                        "Race00",
                                        sf::Style::Close | sf::Style::Titlebar);
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

    player1->moveSnake();
    player1->drawSnake();
    food->drawFood();


    if (CheckCollision(player1->getBody().front(), food->getFood())) {
        sf::Vector2f newLocation = food->getNewPosition(player1->getBody());

        food->changeLocation(newLocation);
    }
    int gameSpeed = 60 - player1->getSnakeLength();
    this->window->setFramerateLimit(gameSpeed <= 10 ? 10 : gameSpeed);
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
