/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** GameWon
*/

#ifndef GAMEWON_HPP_
#define GAMEWON_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class GameWon {
    public:
        GameWon();
        ~GameWon();
        void drawEnd(sf::RenderWindow *w);
        void updateText();
    private:
        sf::Font _font;
        sf::Text _gameWonText;
        sf::Text _menuText;
        sf::Text _quitText;
        sf::Clock _textClock;
};

#endif /* !GAMEWON_HPP_ */
