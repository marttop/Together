/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Ship
*/

#ifndef SHIP_HPP_
#define SHIP_HPP_

#include "Entity.hpp"

class Ship : public Entity {
    public:
        Ship(sf::Texture *texture, sf::Vector2f pos, sf::IntRect rectangle);
        ~Ship();

    protected:
    private:
};

#endif /* !SHIP_HPP_ */