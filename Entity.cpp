/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(sf::Texture *texture, sf::Vector2f pos)
{
    _texture = texture;
    _pos = pos;
    _sprite = new sf::Sprite(*this->_texture);
}

Entity::~Entity()
{
    if (_texture)
        delete _texture;
    if (_sprite)
        delete _sprite;
}
