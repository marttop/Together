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
#include "NyanCat.hpp"
#include "Parallax.hpp"
#include <memory>
#include <ctime>


enum Scene {
    MENU,
    GAME,
    GAME_OVER,
    PROLOGUE,
    GAME_WON,
};

class Player;
class NyanCat;

extern Scene global_scene;
extern string global_language;
extern sf::Clock mainClock;
extern int global_nyan;
extern bool gameOver;

using namespace std;


class EntityController {
    public:
        EntityController(Player *player);
        ~EntityController();

        enum Textures {
            ASTEROID,
            NYANCAT
        };

        void addAsteroid(sf::Vector2f pos);
        void drawAll(sf::RenderWindow *w) const;
        void updateAll();
        void createRandomAsteroids();
        void createRandomNyanCat();
        void destroyAsteroids();
        void updateAsteroids();
        void updatePlayer();
        void checkShooting();
        void deleteAsteroids();
        void addNyan(sf::Vector2f pos);
        void updateNyanCat();
        void destroyNyanCat();
        void deleteNyanCat();

    protected:
    private:
        sf::Clock _asteroidClock;
        sf::Clock _nyanClock;
        vector <Asteroid *> _asteroid;
        vector <sf::Texture *> _textures;
        vector <NyanCat *> _nyanCat;
        Player *_player;
        Parallax *_parallax;
        Utils _utils;
        float _randTimeAsteroids;
        float _randTimeNyan;


        sf::Font _font;
        sf::Text _nyanScore;
        sf::Text _timer;
};

#endif /* !ENTITYCONTROLLER_HPP_ */