/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** GameOver
*/

#include "GameOver.hpp"

GameOver::GameOver()
{
    _textClock.restart();
    _font.loadFromFile("src/fonts/RetroGaming.ttf");
    _gameOverText.setFont(_font);
    _gameOverText.setFillColor(sf::Color::White);
    if (global_language == ".fr") {
        _gameOverText.setCharacterSize(150);
        _gameOverText.setString("VOUS AVEZ PERDU!");
        _gameOverText.setPosition(sf::Vector2f{100, 1080});
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
        _gameOverText.setCharacterSize(200);
        _gameOverText.setString("GAME OVER!");
        _gameOverText.setPosition(sf::Vector2f{310, 1080});
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

GameOver::~GameOver()
{
}

void GameOver::drawEnd(sf::RenderWindow *w)
{
    w->draw(_gameOverText);
    w->draw(_menuText);
    w->draw(_quitText);
}

void GameOver::updateText()
{
    float y = _gameOverText.getPosition().y;
    float y1 = _menuText.getPosition().y;
    float y2 = _quitText.getPosition().y;
    if (_textClock.getElapsedTime().asSeconds() > 0.0005) {
        if (y > 200) {
            if (global_language == ".fr") {
                _gameOverText.setPosition(sf::Vector2f{100, y - 3});
                _menuText.setPosition(sf::Vector2f{520, y1 - 3});
                _quitText.setPosition(sf::Vector2f{520, y2 - 3});
            }
            else if (global_language == ".en") {
                _gameOverText.setPosition(sf::Vector2f{330, y - 3});
                _menuText.setPosition(sf::Vector2f{540, y1 - 3});
                _quitText.setPosition(sf::Vector2f{600, y2 - 3});
            }
        }
        _textClock.restart();
    }
}