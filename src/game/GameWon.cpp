/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** GameWon
*/

#include "GameWon.hpp"

GameWon::GameWon()
{
    _textClock.restart();
    _font.loadFromFile("src/fonts/RetroGaming.ttf");
    _gameWonText.setFont(_font);
    _gameWonText.setFillColor(sf::Color::White);
    if (global_language == ".fr") {
        _gameWonText.setCharacterSize(150);
        _gameWonText.setString("VOUS L'AVEZ FAIT!");
        _gameWonText.setPosition(sf::Vector2f{100, 1080});
        _menuText.setFont(_font);
        _menuText.setFillColor(sf::Color::White);
        _menuText.setCharacterSize(40);
        _menuText.setString("Appuyez sur 'M' pour retourner menu");
        _menuText.setPosition(sf::Vector2f{520, 1430});
        _quitText.setFont(_font);
        _quitText.setFillColor(sf::Color::White);
        _quitText.setCharacterSize(40);
        _quitText.setString("Appuyez sur 'ESC' pour quiter le jeu");
        _quitText.setPosition(sf::Vector2f{520, 1530});
    }
    else if (global_language == ".en") {
        _gameWonText.setCharacterSize(200);
        _gameWonText.setString("YOU DID IT!");
        _gameWonText.setPosition(sf::Vector2f{310, 1080});
        _menuText.setFont(_font);
        _menuText.setFillColor(sf::Color::White);
        _menuText.setCharacterSize(40);
        _menuText.setString("Press 'M' to go back to the menu");
        _menuText.setPosition(sf::Vector2f{540, 1430});
        _quitText.setFont(_font);
        _quitText.setFillColor(sf::Color::White);
        _quitText.setCharacterSize(40);
        _quitText.setString("Press 'ESC' to quit the game");
        _quitText.setPosition(sf::Vector2f{600, 1530});

    }
}

GameWon::~GameWon()
{
}

void GameWon::drawEnd(sf::RenderWindow *w)
{
    w->draw(_gameWonText);
    w->draw(_menuText);
    w->draw(_quitText);
}

void GameWon::updateText()
{
    float y = _gameWonText.getPosition().y;
    float y1 = _menuText.getPosition().y;
    float y2 = _quitText.getPosition().y;
    if (_textClock.getElapsedTime().asSeconds() > 0.0005) {
        if (y > 200) {
            if (global_language == ".fr") {
                _gameWonText.setPosition(sf::Vector2f{100, y - 3});
                _menuText.setPosition(sf::Vector2f{520, y1 - 3});
                _quitText.setPosition(sf::Vector2f{520, y2 - 3});
            }
            else if (global_language == ".en") {
                _gameWonText.setPosition(sf::Vector2f{310, y - 3});
                _menuText.setPosition(sf::Vector2f{540, y1 - 3});
                _quitText.setPosition(sf::Vector2f{600, y2 - 3});
            }
        }
        _textClock.restart();
    }
}
