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
    _player = new Player;
    _controller = new EntityController(_player);

    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPointSize(7);
}

Game::~Game()
{
    delete _player;
    delete _controller;
}

void Game::handleEvents()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_event.type == sf::Event::KeyPressed)
            _player->setShipMove(_event.key.code);
        if (_event.type == sf::Event::KeyReleased)
            _player->unsetShipMove(_event.key.code);
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
    while (_window.isOpen()) {
        handleEvents();
        clear();
        _controller->updateAll();
        _controller->drawAll(&_window);
        display();
    }
}