/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Player
*/

#include "Player.hpp"

Player::Player()
{
    // _shipTextures[0].loadFromFile("assets/asteroid1.png");
    //_shipTextures[1].loadFromFile("assets/nebula_aqua_pink.png");
    // _ship1 = new Ships(&_shipTextures[0], sf::Vector2f{0, 0});
    //_ship2 = new Ships(&_shipTextures[1], sf::Vector2f{0, 0});
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