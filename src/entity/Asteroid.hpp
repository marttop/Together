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
        sf::Sprite &getHitboxSprite();
        bool isColliding(Entity *other);
        void reduceScale();
        sf::Vector2f getscale() const;
    protected:
    private:
        int _direction;
        sf::Clock _rotationClock;
        float _rotationSpeed;
        int _trail;
        sf::Sprite *_hitboxSprite;
};

#endif /* !ASTEROID_HPP_ */
