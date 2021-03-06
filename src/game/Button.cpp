/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Button
*/

#include "Button.hpp"
#include "Game.hpp"
#include <iostream>

Button::Button(sf::Texture *texture, sf::Vector2f pos, string filepath, string language) : Entity(texture, pos)
{
    ifstream file;
    string line;
    file.open(filepath + language);
    _alpha = 0;
    _lang = language;
    _path = filepath;
    _btnText.setPosition(sf::Vector2f{pos.x + 5, pos.y + 5});
    _btnText.setFillColor(sf::Color{255, 255, 255, 0});
    _sprite->setColor(sf::Color{255, 255, 255, 0});
    loadTxt();
}

void Button::loadTxt()
{
    ifstream file;
    string line;
    file.open(_path + _lang);
    if (file.is_open()) {
        getline(file, line);
        _btnText.setString(line);
        file.close();
    }
}

void Button::setFont(sf::Font &font)
{
    _btnText.setFont(font);
}

void Button::drawButton(sf::RenderWindow *w) const
{
    w->draw(this->getSprite());
    w->draw(_btnText);
}

sf::Color Button::getColor() const
{
    return (_sprite->getColor());
}

void Button::setColor(sf::Color color)
{
    _alpha = color.a;
    this->_sprite->setColor(color);
    this->_btnText.setFillColor(sf::Color{255, 255, 255, color.a});
}

void Button::setLang(string &lang)
{
    _lang = lang;
    loadTxt();
}

void Button::btnHover(sf::RenderWindow *w)
{
    if (isMouseOnSprite(w)) {
        this->_sprite->setColor(sf::Color(3, 211, 252, _alpha));
    } else {
        this->_sprite->setColor(sf::Color(255, 255, 255, _alpha));
    }
}

Button::~Button()
{
}
