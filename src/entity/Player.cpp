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
    sf::Keyboard::Key *keys1 = new sf::Keyboard::Key[5];
    keys1[0] = sf::Keyboard::Z, keys1[1] = sf::Keyboard::S, keys1[2] = sf::Keyboard::Q, keys1[3] = sf::Keyboard::D, keys1[4] = sf::Keyboard::Space;
    _ship1 = new Ship(&_shipTextures, sf::Vector2f{1920 / 3 - ((float)_shipTextures.getSize().x / 3 / 2), (1080 / 8) * 6},
                        sf::IntRect{(int)_shipTextures.getSize().x / 3, 0, (int)_shipTextures.getSize().x / 3, (int)_shipTextures.getSize().y}, keys1);
    sf::Keyboard::Key *keys2 = new sf::Keyboard::Key[5];
    keys2[0] = sf::Keyboard::Up, keys2[1] = sf::Keyboard::Down, keys2[2] = sf::Keyboard::Left, keys2[3] = sf::Keyboard::Right, keys2[4] = sf::Keyboard::Space;
    _ship2 = new Ship(&_shipTextures, sf::Vector2f{(1920 / 3 - ((float)_shipTextures.getSize().x / 3 / 2)) * 2, (1080 / 8) * 6},
                        sf::IntRect{(int)_shipTextures.getSize().x / 3, 0, (int)_shipTextures.getSize().x / 3, (int)_shipTextures.getSize().y}, keys2);
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
    _ship1->drawParticles(w);
    _ship2->drawParticles(w);
    glBegin(GL_LINES);
    glLineWidth(5.0f);
    glVertex2f(_ship1->getSprite().getPosition().x + 8, _ship1->getSprite().getPosition().y);
    glVertex2f(_ship2->getSprite().getPosition().x + 8, _ship2->getSprite().getPosition().y);
    glEnd();
    w->draw(_ship1->getSprite());
    w->draw(_ship2->getSprite());
}

void Player::update()
{
    _ship1->update();
    _ship2->update();
}

void Player::setShipMove(sf::Keyboard::Key key)
{
    _ship1->setMove(key);
    _ship2->setMove(key);
}

void Player::unsetShipMove(sf::Keyboard::Key key)
{
    _ship1->unsetMove(key);
    _ship2->unsetMove(key);
}

pair<Ship *, Ship *> Player::getShips() const
{
    return (make_pair(_ship1, _ship2));
}