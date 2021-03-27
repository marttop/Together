/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Ship
*/

#include "Ship.hpp"

Ship::Ship(sf::Texture *texture, sf::Vector2f pos, sf::IntRect rectangle) : Entity(texture, pos)
{
    _sprite->setTextureRect(rectangle);
}

Ship::~Ship()
{
}