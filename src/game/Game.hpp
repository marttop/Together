/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <math.h>
#include "EntityController.hpp"
#include "Utils.hpp"
#include "Menu.hpp"
#include "ChatBox.hpp"
#include "Prologue.hpp"
#include "GameOver.hpp"
#include "EndLost.hpp"
#include "GameWon.hpp"
#include "EndWin.hpp"

class Game;
using namespace std;

class Game {
    public:
        Game(const std::string &winTitle, size_t width, size_t height);
        ~Game();

        void run();
        void setReset(bool r);

    private:
        void handleEvents();
        void menuEvents();
        void clear();
        void display();

        sf::RenderWindow _window;
        sf::Event _event;
        EntityController *_controller;
        Player *_player;
        Menu _menu;
        Scene _scene;
        ChatBox box;
        Prologue _prologue;
        GameOver _gameOver;
        GameWon _gameWon;
        ParticleSystem *_particles;
        bool _reset;
        EndLost _endLost;
        sf::Music _music;
        EndWin _endWin;
};

#endif /* !GAME_HPP_ */
