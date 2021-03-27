/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** EntityController
*/

#include "EntityController.hpp"

EntityController::EntityController()
{
    sf::Texture text;
    this->_textures.push_back(make_shared<sf::Texture>());
    this->_textures[ASTEROID]->loadFromFile("assets/asteroid1.png");
}

EntityController::~EntityController()
{
}

void EntityController::drawAll(sf::RenderWindow *w) const
{
    for (auto a : _asteroid) {
        w->draw(a->getSprite());
    }
}