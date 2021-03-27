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
#include <string>

class Game {
    public:
        Game(const std::string &winTitle, size_t width, size_t height);
        ~Game();
        void handleEvents();
        void clear();
        void display();
    private:
        sf::RenderWindow window;
        sf::Event event;
};

#endif /* !GAME_HPP_ */
