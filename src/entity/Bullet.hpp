/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Bullet
*/

#ifndef BULLET_HPP_
#define BULLET_HPP_

#include "Entity.hpp"

class Bullet : public Entity {
    public:
        Bullet(sf::Texture *texture, sf::Vector2f pos, sf::IntRect rect);
        ~Bullet();

    protected:
    private:
};

#endif /* !BULLET_HPP_ */