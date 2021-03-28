/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Bullet
*/

#include "Bullet.hpp"

Bullet::Bullet(sf::Texture *texture, sf::Vector2f pos, sf::IntRect rect) : Entity(texture, pos)
{
    _sprite->setTextureRect(rect);
    _sprite->setOrigin(sf::Vector2f{(float)rect.width / 2, (float)rect.height / 2});
}

Bullet::~Bullet()
{
}