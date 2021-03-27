/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Enemy
*/

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "Entity.hpp"

class Enemy : public Entity {
    public:
        Enemy(sf::Texture *texture, sf::Vector2f pos);
        ~Enemy();

    protected:
    private:
};

#endif /* !ENEMY_HPP_ */
