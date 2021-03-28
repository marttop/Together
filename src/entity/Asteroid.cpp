/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Asteroid
*/

#include "Asteroid.hpp"

Asteroid::Asteroid(sf::Texture *texture, sf::Vector2f pos, float speed) : Enemy(texture, pos, speed)
{
    _direction = rand() % 2 ? 1 : -1;
    _rotationClock.restart();
    sf::Vector2u origin = _texture->getSize();
    scaleAsteroid();
    _sprite->setOrigin(sf::Vector2f{(float)origin.x / 2, (float)origin.y / 2});
    _particleSystem = new ParticleSystem();
}

Asteroid::~Asteroid()
{
}

void Asteroid::scaleAsteroid()
{
    if (this->_speed == 2) {
        this->_sprite->setScale(sf::Vector2f{1.3, 1.3});
        _rotationSpeed = 1;
        _trail = 40;
    }
    else if (this->_speed == 4) {
        this->_sprite->setScale(sf::Vector2f{0.7, 0.7});
        _rotationSpeed = 3;
        _trail = 80;
    }
    else if (this->_speed == 5) {
        this->_sprite->setScale(sf::Vector2f{0.5, 0.5});
        _trail = 100;
    }
    else {
        _rotationSpeed = 2;
        _trail = 60;
    }
}

void Asteroid::moveAsteroid()
{
    if (getElapsedTime() > 0.01) {
        sf::Vector2f pos = getSprite().getPosition();
        setPos(sf::Vector2f{pos.x, pos.y + _speed});
        _clock.restart();
        _particleSystem->update(sf::Vector2f{float(-10 + rand() % 10), 0}, sf::Vector2f{_pos.x, _pos.y - 20}, _pos, sf::Color{0, 125, 255, 255}, sf::Color{255, 255, 255, 0}, _trail, 1);
    }
}

void Asteroid::rotateAsteroid()
{
    if (this->_rotationClock.getElapsedTime().asSeconds() > 0.01) {
        _sprite->rotate(_rotationSpeed * _direction);
        _rotationClock.restart();
    }
}