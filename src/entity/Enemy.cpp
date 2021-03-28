/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Enemy
*/

#include "Enemy.hpp"

Enemy::Enemy(sf::Texture *texture, sf::Vector2f pos, float speed) : Entity(texture, pos)
{
    _speed = speed;
}

Enemy::~Enemy()
{
}

float Enemy::getSpeed()
{
    return (_speed);
}

void Enemy::setSpeed(float speed)
{
    _speed = speed;
}