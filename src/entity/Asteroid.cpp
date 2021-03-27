/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Asteroid
*/

#include "Asteroid.hpp"

Asteroid::Asteroid(sf::Texture *texture, sf::Vector2f pos, float speed) : Enemy(texture, pos, speed)
{
    _rotationSpeed = 1 + (rand() % 10);
    _rotationClock.restart();
    sf::Vector2u origin = _texture->getSize();
    _sprite->setOrigin(sf::Vector2f{(float)origin.x / 2, (float)origin.y / 2});
}

Asteroid::~Asteroid()
{
}

void Asteroid::moveAsteroid()
{
    if (getElapsedTime() > 0.01) {
        sf::Vector2f pos = getSprite().getPosition();
        setPos(sf::Vector2f{pos.x, pos.y + _speed});
        _clock.restart();
    }
}

void Asteroid::rotateAsteroid()
{
    if (this->_rotationClock.getElapsedTime().asSeconds() > 0.01) {
        _sprite->rotate(_rotationSpeed);
        _rotationClock.restart();
    }
}