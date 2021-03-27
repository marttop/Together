/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** EntityController
*/

#ifndef ENTITYCONTROLLER_HPP_
#define ENTITYCONTROLLER_HPP_

#include "Asteroid.hpp"
#include "Player.hpp"
#include "Parallax.hpp"
#include <memory>

using namespace std;


class EntityController {
    public:
        EntityController();
        ~EntityController();

        enum Textures {
            ASTEROID,
        };

        void addAsteroid(sf::Vector2f pos);
        void drawAll(sf::RenderWindow *w) const;
        void updateAll();
    protected:
    private:
        vector <Asteroid *> _asteroid;
        vector <sf::Texture *> _textures;
        Player *_player;
        Parallax *_parallax;
};

#endif /* !ENTITYCONTROLLER_HPP_ */
