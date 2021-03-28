/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Ship
*/

#include "Ship.hpp"
#include <iostream>

Ship::Ship(sf::Texture *texture, sf::Vector2f pos, sf::IntRect rectangle, sf::Keyboard::Key *keys, sf::IntRect bulletRect) : Entity(texture, pos)
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
    _isHit = false;
    _hud = new ShipHud();
    _hud->setHp(100);
    _hp = 100;
    _ammoTexture = new sf::Texture;
    _ammoTexture->loadFromFile("assets/beams.png");
    _ammos[0] = new Ammo(_ammoTexture, 1, 20, 0.2, bulletRect);
    _ammos[1] = new Ammo(_ammoTexture, 1, 20, 0.2, bulletRect);
}

Ship::~Ship()
{
    delete _keys;
    delete _inputs;
    delete[] _particleSystem;
    delete _ammoTexture;
    delete _ammos[0];
    delete _ammos[1];
}

void Ship::update(sf::Color startColor, sf::Color endColor)
{
    if (_pos.x >= 1915 - _sprite->getLocalBounds().width / 2)
        _inputs[3] = false;
    if (_pos.x <= -5 + _sprite->getLocalBounds().width / 2)
        _inputs[2] = false;
    if (_pos.y >= 1000 - _sprite->getLocalBounds().height / 2)
        _inputs[1] = false;
    if (_pos.y <= 15 + _sprite->getLocalBounds().height / 2)
        _inputs[0] = false;
    if (_inputs[0] == true && _inputs[2] == true && _inputs[1] == false && _inputs[3] == false) setPos(sf::Vector2f{getSprite().getPosition().x - (_speed / 2), getSprite().getPosition().y - (_speed / 2)});
    else if (_inputs[0] == true && _inputs[3] == true && _inputs[1] == false && _inputs[2] == false) setPos(sf::Vector2f{getSprite().getPosition().x + (_speed / 2), getSprite().getPosition().y - (_speed / 2)});
    else if (_inputs[1] == true && _inputs[2] == true && _inputs[0] == false && _inputs[3] == false) setPos(sf::Vector2f{getSprite().getPosition().x - (_speed / 2), getSprite().getPosition().y + (_speed / 2)});
    else if (_inputs[1] == true && _inputs[3] == true && _inputs[0] == false && _inputs[2] == false) setPos(sf::Vector2f{getSprite().getPosition().x + (_speed / 2), getSprite().getPosition().y + (_speed / 2)});
    else if (_inputs[0] == true && _inputs[1] == false) setPos(sf::Vector2f{getSprite().getPosition().x, getSprite().getPosition().y - _speed});
    else if (_inputs[1] == true && _inputs[0] == false) setPos(sf::Vector2f{getSprite().getPosition().x, getSprite().getPosition().y + _speed});
    else if (_inputs[2] == true && _inputs[3] == false) setPos(sf::Vector2f{getSprite().getPosition().x - _speed, getSprite().getPosition().y});
    else if (_inputs[3] == true && _inputs[2] == false) setPos(sf::Vector2f{getSprite().getPosition().x + _speed, getSprite().getPosition().y});
    _pos = _sprite->getPosition();
    _particleSystem[0].update(sf::Vector2f{0, 0}, sf::Vector2f{_pos.x + 25, _pos.y + 50}, sf::Vector2f{_pos.x + 30, _pos.y + 10}, startColor, endColor, 15, 1);
    _particleSystem[1].update(sf::Vector2f{0, 0}, sf::Vector2f{_pos.x - 10, _pos.y + 50}, sf::Vector2f{_pos.x - 15, _pos.y + 10}, startColor, endColor, 15, 1);
    if (_inputs[4] == true) {
        _ammos[0]->shoot(sf::Vector2f{_pos.x, _pos.y});
        _ammos[1]->shoot(sf::Vector2f{_pos.x + 25, _pos.y});
    }
    _ammos[0]->update();
    _ammos[1]->update();
}

void Ship::moveShipRect()
{
    if (_inputs[2] == true && _inputs[3] == true) _rect.left = _rectOffset;
    else if (_inputs[2] == true) _rect.left = 0;
    else if (_inputs[3] == true) _rect.left = _rectOffset * 2;
    else _rect.left = _rectOffset;
    _sprite->setTextureRect(_rect);
}

void Ship::setInputs(sf::Keyboard::Key key)
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

void Ship::unSetInputs(sf::Keyboard::Key key)
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

void Ship::drawAmmos(sf::RenderWindow *w)
{
    _ammos[0]->drawAmmos(w);
    _ammos[1]->drawAmmos(w);
}

void Ship::checkIfHit()
{
    if (!_isHit) {
        return;
    }
}

sf::Text Ship::getName() const
{
    return _hud->getName();
}

sf::RectangleShape Ship::getBox() const
{
    return _hud->getBox();
}

sf::RectangleShape Ship::getBar() const
{
    return _hud->getBar();
}

sf::RectangleShape Ship::getHpRect() const
{
    return _hud->getHpRect();
}

ShipHud *Ship::getHud() const
{
    return _hud;
}

float Ship::getHpShip() const
{
    return _hp;
}

void Ship::setHpShip(float newHp)
{
    _hp = newHp;
}

Ammo &Ship::getAmmos(int i)
{
    // if (i > 1) return (nullptr);
    return (*_ammos[i]);
}