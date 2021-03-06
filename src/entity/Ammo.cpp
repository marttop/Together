/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Ammo
*/

#include "Ammo.hpp"

Ammo::Ammo(sf::Texture *texture, bool direction, int speed, float cadency, sf::IntRect rect)
{
    _texture = texture;
    _shootClock.restart();
    _updateClock.restart();
    _direction = direction;
    _speed = speed;
    _cadency = cadency;
    _rect = rect;
}

Ammo::~Ammo()
{
}

void Ammo::shoot(sf::Vector2f pos)
{
    if (_shootClock.getElapsedTime().asSeconds() > _cadency) {
        _pos = pos;
        _ammos.push_back(new Bullet(_texture, _pos, _rect));
        _shootClock.restart();
    }
}

void Ammo::update()
{
    int index = 0;
    if (_direction == false) {
        for (auto i : _ammos) {
            i->setPos(sf::Vector2f(i->getPos().x, i->getPos().y + _speed * _updateClock.getElapsedTime().asSeconds()));
            if (i->getPos().y >= 2000)
                _ammos.erase(_ammos.begin() + index);
            index++;
        }
    }
    else {
        for (auto i : _ammos) {
            i->setPos(sf::Vector2f(i->getPos().x, i->getPos().y - _speed));
            if (i->getPos().y <= -1000)
                _ammos.erase(_ammos.begin() + index);
            index++;
        }
    }
}

void Ammo::drawAmmos(sf::RenderWindow *w)
{
    for (auto i : _ammos) {
        w->draw(i->getSprite());
    }
}

void Ammo::setRect(sf::IntRect rect)
{
    _rect = rect;
}

vector<Bullet *> &Ammo::getLasers()
{
    return (_ammos);
}