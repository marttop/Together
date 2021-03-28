/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** GameOver
*/

#ifndef GAMEOVER_HPP_
#define GAMEOVER_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "EntityController.hpp"

class GameOver {
    public:
        GameOver();
        ~GameOver();
        void drawEnd(sf::RenderWindow *w);
        void updateText();
        void setTextLang();
    private:
        sf::Font _font;
        sf::Text _gameOverText;
        sf::Text _menuText;
        sf::Text _quitText;
        sf::Clock _textClock;
};

#endif /* !GAMEOVER_HPP_ */
