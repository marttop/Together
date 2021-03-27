/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Ship
*/

#ifndef SHIP_HPP_
#define SHIP_HPP_

#include "Entity.hpp"

using namespace std;

class Ship : public Entity {
    public:
        Ship(sf::Texture *texture, sf::Vector2f pos, sf::IntRect rectangle, sf::Keyboard::Key *keys);
        ~Ship();

        void update();
        void setMove(sf::Keyboard::Key key);
        void unsetMove(sf::Keyboard::Key key);
        void drawParticles(sf::RenderWindow *w);

    protected:
    private:
        void moveShipRect();

        sf::Keyboard::Key *_keys;
        float _speed;
        bool *_inputs;
        int _rectOffset;
        sf::IntRect _rect;
};

#endif /* !SHIP_HPP_ */