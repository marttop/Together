/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** ShipHud
*/

#include "ShipHud.hpp"

ShipHud::ShipHud()
{
    _hpRect.setSize(sf::Vector2f{276, 16});
    _hpRect.setFillColor(sf::Color::Green);
    _barRect.setSize(sf::Vector2f{280, 20});
    _barRect.setOutlineThickness(2.0);
    _barRect.setOutlineColor(sf::Color::White);
    _barRect.setFillColor(sf::Color::Transparent);
    _box.setSize(sf::Vector2f{300, 150});
    _box.setOutlineThickness(2.0);
    _box.setOutlineColor(sf::Color::White);
    _box.setFillColor(sf::Color::Transparent);
    _font.loadFromFile("src/fonts/RetroGaming.ttf");
    _textName.setFont(_font);
    _textName.setFillColor(sf::Color::White);
    _textName.setCharacterSize(20);
}

ShipHud::~ShipHud()
{
}

void ShipHud::setName(std::string name)
{
    _name = name;
    _textName.setString(_name);
}

void ShipHud::setPositions(int left)
{
    if (left == 0) {
        _hpRect.setPosition(sf::Vector2f{42, 1002});
        _barRect.setPosition(sf::Vector2f{40, 1000});
        _box.setPosition(sf::Vector2f{30, 920});
        _textName.setPosition(sf::Vector2f{40, 950});
    }
    else {
        _hpRect.setPosition(sf::Vector2f{1602, 1002});
        _barRect.setPosition(sf::Vector2f{1600, 1000});
        _box.setPosition(sf::Vector2f{1590, 920});
        _textName.setPosition(sf::Vector2f{1600, 950});
    }
}

sf::Text ShipHud::getName() const
{
    return _textName;
}

sf::RectangleShape ShipHud::getBox() const
{
    return _box;
}

sf::RectangleShape ShipHud::getBar() const
{
    return _barRect;
}

sf::RectangleShape ShipHud::getHpRect() const
{
    return _hpRect;
}

void ShipHud::updateHp(float hp)
{
    float x = 0;

    x = (hp * 276) / _hpTotal;

    if (x < 0)
        _hpRect.setSize(sf::Vector2f{0, 16});
    else
        _hpRect.setSize(sf::Vector2f{x, 16});
    float y = 0;

    y = (hp * 100) / _hpTotal;

    if (y > 66)
        _hpRect.setFillColor(sf::Color::Green);
    else if (y > 33 && y <= 66)
        _hpRect.setFillColor(sf::Color::Yellow);
    if (y > 0 && y <= 33)
        _hpRect.setFillColor(sf::Color::Red);
}

void ShipHud::setHp(float hp)
{
    _hpTotal = hp;
}
