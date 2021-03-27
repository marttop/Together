/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Player
*/

#include "Player.hpp"

Player::Player()
{
    _shipTextures.loadFromFile("assets/player_ship.png");
    _ship1 = new Ship(&_shipTextures, sf::Vector2f{1920 / 3 - ((float)_shipTextures.getSize().x / 3 / 2), (1080 / 8) * 6},
                        sf::IntRect{(int)_shipTextures.getSize().x / 3, 0, (int)_shipTextures.getSize().x / 3, (int)_shipTextures.getSize().y});
    _ship2 = new Ship(&_shipTextures, sf::Vector2f{(1920 / 3 - ((float)_shipTextures.getSize().x / 3 / 2)) * 2, (1080 / 8) * 6},
                        sf::IntRect{(int)_shipTextures.getSize().x / 3, 0, (int)_shipTextures.getSize().x / 3, (int)_shipTextures.getSize().y});
}

Player::~Player()
{
    if (_ship1) delete _ship1;
    if (_ship2) delete _ship2;
}

sf::Sprite &Player::getSprite(int i) const
{
    if (i == 1) return (_ship1->getSprite());
    else return (_ship2->getSprite());
}

void Player::drawPlayer(sf::RenderWindow *w)
{
    w->draw(_ship1->getSprite());
    w->draw(_ship2->getSprite());
}