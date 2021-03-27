/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** EntityController
*/

#include "EntityController.hpp"

EntityController::EntityController()
{
    _textures.push_back(new sf::Texture);
    _textures[ASTEROID]->loadFromFile("assets/asteroid1.png");
    _player = new Player;
}

EntityController::~EntityController()
{
    for (auto iter : _textures)
        delete iter;
    for (auto iter : _asteroid)
        delete iter;
}

void EntityController::drawAll(sf::RenderWindow *w) const
{
    for (auto a : _asteroid)
        w->draw(a->getSprite());
    w->draw(_player->getSprite(1));
    w->draw(_player->getSprite(2));
}

void EntityController::addAsteroid(sf::Vector2f pos)
{
    _asteroid.push_back(new Asteroid(_textures[ASTEROID], pos));
}