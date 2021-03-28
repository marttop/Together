/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Asteroid
*/

#ifndef ASTEROID_HPP_
#define ASTEROID_HPP_

#include "Enemy.hpp"

class Asteroid : public Enemy {
    public:
        Asteroid(sf::Texture *texture, sf::Vector2f pos, float speed);
        ~Asteroid();

        void moveAsteroid();
        void rotateAsteroid();
        void scaleAsteroid();
    protected:
    private:
        int _direction;
        sf::Clock _rotationClock;
        float _rotationSpeed;
        int _trail;
};

#endif /* !ASTEROID_HPP_ */
