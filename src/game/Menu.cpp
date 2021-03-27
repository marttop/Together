/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
    _title.setString("Together");
    _font.loadFromFile("fonts/retro_gaming.ttf");
    _title.setFont(_font);
    _bckgrTexture.loadFromFile("assets/saturn.png");
    _background = new Layer(&_bckgrTexture, sf::Vector2f{0, 0}, true);
    _background->setColor(sf::Color{255, 255, 255, 0});
    _title.setCharacterSize(40);
    _title.setPosition(sf::Vector2f{10, 10});
    _title.setFillColor(sf::Color{255, 255, 255, 0});
    _btnTexture.loadFromFile("assets/button.png");
    _buttons.push_back(new Button(&_btnTexture, sf::Vector2f{50, 75}, "res/btn_start", ".en"));
    _buttons.push_back(new Button(&_btnTexture, sf::Vector2f{50, 130}, "res/btn_exit", ".en"));
    _buttons[0]->setFont(_font);
    _buttons[1]->setFont(_font);
}

void Menu::menuAnimation()
{
    sf::Color color = this->_background->getColor();
    if (color.a < 255) {
        if (this->_clock.getElapsedTime().asSeconds() > 0.04) {
            color.a += 5;
            this->_background->setColor(color);
            this->_title.setFillColor(color);
            this->_clock.restart();

            for (auto itr : _buttons) {
                itr->setColor(color);
            }
        }
    }
}

void Menu::displayMenu(sf::RenderWindow *w)
{
    w->draw(_background->getSprite());
    w->draw(_title);
    for (auto itr : _buttons) {
        itr->drawButton(w);
        itr->btnHover(w);
    }
}

Menu::~Menu()
{
    if (this->_background)
        delete this->_background;
}
