/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Ammo
*/

#ifndef AMMO_HPP_
#define AMMO_HPP_

#include "Bullet.hpp"

using namespace std;

class Ammo {
    public:
        Ammo(sf::Texture *texture, bool direction, int speed, float cadency, sf::IntRect rect);
        ~Ammo();
        void shoot(sf::Vector2f pos);
        void drawAmmos(sf::RenderWindow *w);
        void update();
        void setRect(sf::IntRect rect);
        vector<Bullet *> &getLasers();

    protected:
    private:
        sf::Texture *_texture;
        std::vector<Bullet *> _ammos;
        sf::Clock _shootClock;
        sf::Clock _updateClock;
        sf::Vector2f _pos;
        sf::IntRect _rect;
        bool _direction;
        int _speed;
        float _cadency;
};

#endif /* !AMMO_HPP_ */