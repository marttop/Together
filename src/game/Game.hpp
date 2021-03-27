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
#include <string>
#include <vector>
#include <math.h>
#include "EntityController.hpp"
#include "Utils.hpp"
#include "Menu.hpp"
#include "ChatBox.hpp"

using namespace std;

class Game {
    public:
        Game(const std::string &winTitle, size_t width, size_t height);
        ~Game();

        void run();

        enum Scene {
            MENU,
            GAME
        };
    private:
        void handleEvents();
        void clear();
        void display();

        sf::RenderWindow _window;
        sf::Event _event;
        EntityController *_controller;
        Player *_player;
        Menu _menu;
        Scene _scene;
        string _language;
        ChatBox box;
};

#endif /* !GAME_HPP_ */
