/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Ships
*/

#ifndef SHIPS_HPP_
#define SHIPS_HPP_

#include "Entity.hpp"

class Ships : public Entity {
    public:
        Ships(sf::Texture *texture, sf::Vector2f pos);
        ~Ships();

    protected:
    private:
};

#endif /* !SHIPS_HPP_ */