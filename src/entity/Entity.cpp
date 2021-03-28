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
    _sprite = new sf::Sprite(*_texture);
    _sprite->setPosition(pos);
    _clock.restart();
    _particleSystem = nullptr;
}

bool Entity::isMouseOnSprite(sf::RenderWindow *w) const
{
    sf::Vector2i pos = sf::Mouse::getPosition(*w);
    if (_sprite->getGlobalBounds().contains(sf::Vector2f(pos))) {
        return (true);
    }
    return (false);
}

bool Entity::isColliding(Entity &other)
{
    sf::FloatRect rect1 = _sprite->getGlobalBounds();
    sf::FloatRect rect2 = other.getSprite().getGlobalBounds();
    if (rect1.intersects(rect2)) {
        return (true);
    }
    return (false);
}

sf::Sprite &Entity::getSprite() const
{
    return (*_sprite);
}

float Entity::getElapsedTime() const
{
    return (_clock.getElapsedTime().asSeconds());
}

void Entity::restartClock()
{
    _clock.restart();
}

sf::Vector2f Entity::getPos() const
{
    return (_pos);
}

sf::Vector2f Entity::getSize() const
{
    return (sf::Vector2f{_sprite->getGlobalBounds().width, _sprite->getGlobalBounds().height});
}

void Entity::setPos(sf::Vector2f pos)
{
    _pos = pos;
    _sprite->setPosition(_pos);
}

void Entity::setRotation(float angle)
{
    _sprite->rotate(angle);
}

Entity::~Entity()
{
    if (_sprite)
        delete _sprite;
}

void Entity::drawParticles(sf::RenderWindow *w)
{
    _particleSystem->drawParticles(w);
}