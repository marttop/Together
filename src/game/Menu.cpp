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
    _smallBtnTexture.loadFromFile("assets/small_button.png");
    _buttons.push_back(new Button(&_btnTexture, sf::Vector2f{50, 75}, "res/btn_start", global_language));
    _buttons.push_back(new Button(&_btnTexture, sf::Vector2f{50, 130}, "res/btn_exit", global_language));
    _buttons.push_back(new Button(&_smallBtnTexture, sf::Vector2f{1750, 10}, "res/btn_fr", ""));
    _buttons.push_back(new Button(&_smallBtnTexture, sf::Vector2f{1825, 10}, "res/btn_en", ""));
    for (auto itr : _buttons)
        itr->setFont(_font);
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
                color = itr->getColor();
                color.a += 5;
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
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            itr->btnHover(w);
    }
}

void Menu::clickButton(sf::RenderWindow *w)
{
    if (this->_background->getColor().a >= 255) {
        for (auto itr : _buttons) {
            if (itr->isMouseOnSprite(w))
                itr->setColor(sf::Color{150, 150, 150, 255});
        }
    }
}

void Menu::releaseButton(sf::RenderWindow *w)
{
    if (this->_background->getColor().a >= 255) {
        for (auto itr : _buttons) {
            if (itr->isMouseOnSprite(w)) {
                if (itr == _buttons.at(0))
                    global_scene = GAME;
                if (itr == _buttons.at(1))
                    w->close();
                if (itr == _buttons.at(2) && global_language != ".fr") {
                    global_language = ".fr";
                    updateMenuLang();
                }
                if (itr == _buttons.at(3) && global_language != ".en") {
                    global_language = ".en";
                    updateMenuLang();
                }
            }
        }
    }
}

void Menu::updateMenuLang()
{
    for (auto itr : _buttons) {
        itr->setLang(global_language);
    }
}

Menu::~Menu()
{
    if (this->_background)
        delete this->_background;
}
