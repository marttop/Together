/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Ship
*/

#include "Ship.hpp"
#include <iostream>

Ship::Ship(sf::Texture *texture, sf::Vector2f pos, sf::IntRect rectangle, sf::Keyboard::Key *keys) : Entity(texture, pos)
{
    _keys = keys;
    _sprite->setTextureRect(rectangle);
    _sprite->setOrigin(sf::Vector2f{_sprite->getGlobalBounds().height / 2, _sprite->getGlobalBounds().width / 2});
    _speed = 8;
    _inputs = new bool[5];
    _inputs[0] = false;
    _inputs[1] = false;
    _inputs[2] = false;
    _inputs[3] = false;
    _inputs[4] = false;
    _rect = rectangle;
    _rectOffset = rectangle.left;
    _particleSystem = new ParticleSystem[2];
}

Ship::~Ship()
{
    delete _keys;
    delete _inputs;
}

void Ship::update()
{
    if (_inputs[0] == true && _inputs[2] == true) setPos(sf::Vector2f{getSprite().getPosition().x - (_speed / 2), getSprite().getPosition().y - (_speed / 2)});
    else if (_inputs[0] == true && _inputs[3] == true) setPos(sf::Vector2f{getSprite().getPosition().x + (_speed / 2), getSprite().getPosition().y - (_speed / 2)});
    else if (_inputs[1] == true && _inputs[2] == true) setPos(sf::Vector2f{getSprite().getPosition().x - (_speed / 2), getSprite().getPosition().y + (_speed / 2)});
    else if (_inputs[1] == true && _inputs[3] == true) setPos(sf::Vector2f{getSprite().getPosition().x + (_speed / 2), getSprite().getPosition().y + (_speed / 2)});
    else if (_inputs[0] == true) setPos(sf::Vector2f{getSprite().getPosition().x, getSprite().getPosition().y - _speed});
    else if (_inputs[1] == true) setPos(sf::Vector2f{getSprite().getPosition().x, getSprite().getPosition().y + _speed});
    else if (_inputs[2] == true) setPos(sf::Vector2f{getSprite().getPosition().x - _speed, getSprite().getPosition().y});
    else if (_inputs[3] == true) setPos(sf::Vector2f{getSprite().getPosition().x + _speed, getSprite().getPosition().y});
    _pos = _sprite->getPosition();
    _particleSystem[0].update(sf::Vector2f{0, 0}, sf::Vector2f{_pos.x + 25, _pos.y + 50}, sf::Vector2f{_pos.x + 30, _pos.y + 10}, sf::Color{255, 125, 0, 255}, sf::Color{255, 0, 0, 75}, 15, 1);
    _particleSystem[1].update(sf::Vector2f{0, 0}, sf::Vector2f{_pos.x - 10, _pos.y + 50}, sf::Vector2f{_pos.x - 15, _pos.y + 10}, sf::Color{255, 125, 0, 255}, sf::Color{255, 0, 0, 75}, 15, 1);
}

void Ship::moveShipRect()
{
    if (_inputs[2] == true && _inputs[3] == true) _rect.left = _rectOffset;
    else if (_inputs[2] == true) _rect.left = 0;
    else if (_inputs[3] == true) _rect.left = _rectOffset * 2;
    else _rect.left = _rectOffset;
    _sprite->setTextureRect(_rect);
}

void Ship::setMove(sf::Keyboard::Key key)
{
    int i = 0;
    for (; i < 5; i++)
        if (key == _keys[i]) break;
    if (i == 0) _inputs[0] = true;
    if (i == 1) _inputs[1] = true;
    if (i == 2) _inputs[2] = true;
    if (i == 3) _inputs[3] = true;
    if (i == 4) _inputs[4] = true;
    moveShipRect();
}

void Ship::unsetMove(sf::Keyboard::Key key)
{
    int i = 0;
    for (; i < 5; i++)
        if (key == _keys[i]) break;
    if (i == 0) _inputs[0] = false;
    if (i == 1) _inputs[1] = false;
    if (i == 2) _inputs[2] = false;
    if (i == 3) _inputs[3] = false;
    if (i == 4) _inputs[4] = false;
    moveShipRect();
}

void Ship::drawParticles(sf::RenderWindow *w)
{
    _particleSystem[0].drawParticles(w);
    _particleSystem[1].drawParticles(w);
}