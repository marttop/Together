/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Game
*/

#include "Game.hpp"

Game::Game(const std::string &winTitle, size_t width, size_t height)
{
    _window.create(sf::VideoMode(width, height), winTitle);
    _window.setFramerateLimit(60);
}

Game::~Game()
{
}

void Game::handleEvents()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Enter)
                box.addLine();
        }
    }
}

void Game::clear()
{
    _window.clear(sf::Color::Black);
}

void Game::display()
{
    _window.display();
}

void Game::run()
{
    box.readMessage("src/game/dialog");
    while (_window.isOpen()) {
        handleEvents();
        clear();
        _controller.updateAll();
        _controller.drawAll(&_window);
        box.setDialog();
        box.draw(&_window);
        display();
    }
}