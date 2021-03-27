/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Game
*/

#include "Game.hpp"

Game::Game(const std::string &winTitle, size_t width, size_t height)
{
    window.create(sf::VideoMode(width, height), winTitle);
}

Game::~Game()
{
}

void Game::handleEvents()
{
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::clear()
{
    window.clear(sf::Color::Black);
}

void Game::display()
{
    window.display();
}