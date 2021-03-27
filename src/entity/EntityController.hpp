/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** EntityController
*/

#ifndef ENTITYCONTROLLER_HPP_
#define ENTITYCONTROLLER_HPP_

#include "Asteroid.hpp"
#include <memory>

using namespace std;


class EntityController {
    public:
        EntityController();
        ~EntityController();

        enum Textures {
            ASTEROID,
        };

        void createAsteroid();
        void drawAll(sf::RenderWindow *w) const;
    protected:
    private:
        vector<shared_ptr<Asteroid>> _asteroid;
        vector<shared_ptr<sf::Texture>> _textures;
};

#endif /* !ENTITYCONTROLLER_HPP_ */
