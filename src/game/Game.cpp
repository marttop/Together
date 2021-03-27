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
}

Game::~Game()
{
}

void Game::handleEvents()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
    }
}

void Game::clear()
{
    _window.clear(sf::Color::Black);
}

void Game::run()
{
    while (this->_window.isOpen()) {
        this->handleEvents();
        this->clear();
        this->display();
    }
}

void Game::display()
{
    _window.display();
}