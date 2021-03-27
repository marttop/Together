/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Ships.hpp"

class Player {
    public:
        Player();
        ~Player();
        sf::Sprite &getSprite(int i) const;

    protected:
    private:
        sf::Texture _shipTextures[2];
        Ships *_ship1;
        Ships *_ship2;
};

#endif /* !PLAYER_HPP_ */