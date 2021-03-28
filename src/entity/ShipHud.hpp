/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** ShipHud
*/

#ifndef SHIPHUD_HPP_
#define SHIPHUD_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class ShipHud {
    public:
        ShipHud();
        ~ShipHud();
        void setName(std::string name);
        void setPositions(int player, sf::IntRect r);
        sf::Text getName() const;
        sf::RectangleShape getBox() const;
        sf::RectangleShape getBar() const;
        sf::RectangleShape getHpRect() const;
        void updateHp(float hp);
        void setHp(float hp);
    private:
        sf::Font _font;
        sf::Text _textName;
        sf::RectangleShape _hpRect;
        sf::RectangleShape _barRect;
        sf::RectangleShape _box;
        std::string _name;
        float _hpTotal;
};

#endif /* !SHIPHUD_HPP_ */
