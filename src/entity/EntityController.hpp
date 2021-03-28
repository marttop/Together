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
#include <ctime>

enum Scene {
    MENU,
    GAME,
    GAME_OVER,
};

class Player;

extern Scene global_scene;
extern string global_language;

using namespace std;


class EntityController {
    public:
        EntityController(Player *player);
        ~EntityController();

        enum Textures {
            ASTEROID,
        };

        void addAsteroid(sf::Vector2f pos);
        void drawAll(sf::RenderWindow *w) const;
        void updateAll();
        void createRandomAsteroids();
        void destroyAsteroids();
        void updateAsteroids();
        void updatePlayer();
        void checkShooting();

    protected:
    private:
        sf::Clock _asteroidClock;
        vector <Asteroid *> _asteroid;
        vector <sf::Texture *> _textures;
        Player *_player;
        Parallax *_parallax;
        float _randTime;
};

#endif /* !ENTITYCONTROLLER_HPP_ */
