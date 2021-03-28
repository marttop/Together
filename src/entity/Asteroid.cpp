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
    _sprite->setOrigin(sf::Vector2f{(float)origin.x / 2, (float)origin.y / 2});
    _hitboxSprite = new sf::Sprite(*_texture);
    _hitboxSprite->setPosition(pos);
    _hitboxSprite->setOrigin(sf::Vector2f{(float)origin.x / 2, (float)origin.y / 2});
    scaleAsteroid();
    _particleSystem = new ParticleSystem();
}

Asteroid::~Asteroid()
{
    delete _hitboxSprite;
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
        this->_hitboxSprite->setScale(sf::Vector2f{0.5, 0.5});
        _rotationSpeed = 3;
        _trail = 80;
    }
    else if (this->_speed == 5) {
        this->_sprite->setScale(sf::Vector2f{0.5, 0.5});
        this->_hitboxSprite->setScale(sf::Vector2f{0.3, 0.3});
        _trail = 100;
        _rotationSpeed = 4;
    }
    else {
        this->_hitboxSprite->setScale(sf::Vector2f{0.8, 0.8});
        _rotationSpeed = 2;
        _trail = 60;
    }
}

bool Asteroid::isColliding(Entity *other)
{
    sf::FloatRect rect1 = _hitboxSprite->getGlobalBounds();
    sf::FloatRect rect2 = other->getSprite().getGlobalBounds();
    if (rect1.intersects(rect2)) {
        return (true);
    }
    return (false);
}

sf::Sprite &Asteroid::getHitboxSprite()
{
    return (*_hitboxSprite);
}

void Asteroid::moveAsteroid()
{
    if (getElapsedTime() > 0.01) {
        sf::Vector2f pos = getSprite().getPosition();
        setPos(sf::Vector2f{pos.x, pos.y + _speed});
        _hitboxSprite->setPosition(sf::Vector2f{pos.x, pos.y + _speed});
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

void Asteroid::reduceScale()
{
    sf::Vector2f scale = _sprite->getScale();
    _sprite->setScale(sf::Vector2f{scale.x - 0.1f, scale.y - 0.1f});
    scale = _hitboxSprite->getScale();
    if (scale.x > 0.1f)
        _hitboxSprite->setScale(sf::Vector2f{scale.x - 0.1f, scale.y - 0.1f});
}

sf::Vector2f Asteroid::getscale() const
{
    return (_hitboxSprite->getScale());
}
