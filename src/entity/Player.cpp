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
                        sf::IntRect{(int)_shipTextures.getSize().x / 3, 0, (int)_shipTextures.getSize().x / 3, (int)_shipTextures.getSize().y}, keys1, sf::IntRect{208, 309, 62, 109});
    sf::Keyboard::Key *keys2 = new sf::Keyboard::Key[5];
    keys2[0] = sf::Keyboard::Up, keys2[1] = sf::Keyboard::Down, keys2[2] = sf::Keyboard::Left, keys2[3] = sf::Keyboard::Right, keys2[4] = sf::Keyboard::Space;
    _ship2 = new Ship(&_shipTextures, sf::Vector2f{(1920 / 3 - ((float)_shipTextures.getSize().x / 3 / 2)) * 2, (1080 / 8) * 6},
                        sf::IntRect{(int)_shipTextures.getSize().x / 3, 0, (int)_shipTextures.getSize().x / 3, (int)_shipTextures.getSize().y}, keys2, sf::IntRect{301, 27, 62, 109});
    _ship1->setColor(sf::Color{255, 200, 200, 255});
    _ship2->setColor(sf::Color{200, 200, 255, 255});
    _ship1->getHud()->setName(loadNames("res/player1_name"));
    _ship2->getHud()->setName(loadNames("res/player2_name"));
    _ship1->getHud()->setPositions(0);
    _ship2->getHud()->setPositions(1);
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

string Player::loadNames(string filepath)
{
    ifstream file;
    string line;
    file.open(filepath + global_language);
    if (file.is_open()) {
        getline(file, line);
        file.close();
    }
    return (line);
}

void Player::drawPlayer(sf::RenderWindow *w)
{
    _ship1->drawParticles(w);
    _ship2->drawParticles(w);
    glBegin(GL_LINES);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_MULTISAMPLE);
    glColor4ub(255, 100, 0, 200);
    glVertex2f(_ship1->getSprite().getPosition().x + 8, _ship1->getSprite().getPosition().y);
    glColor4ub(0, 100, 255, 200);
    glVertex2f(_ship2->getSprite().getPosition().x + 8, _ship2->getSprite().getPosition().y);
    glEnd();
    _ship1->drawAmmos(w);
    _ship2->drawAmmos(w);
    w->draw(_ship1->getSprite());
    w->draw(_ship2->getSprite());
    w->draw(_ship1->getBox());
    w->draw(_ship1->getName());
    w->draw(_ship1->getBar());
    w->draw(_ship1->getHpRect());
    w->draw(_ship2->getBox());
    w->draw(_ship2->getName());
    w->draw(_ship2->getBar());
    w->draw(_ship2->getHpRect());
}

void Player::update()
{
    _ship1->update(sf::Color{255, 125, 0, 255}, sf::Color{255, 0, 0, 80});
    _ship2->update(sf::Color{0, 125, 255, 255}, sf::Color{0, 0, 255, 80});
}

void Player::setShipMove(sf::Keyboard::Key key)
{
    _ship1->setInputs(key);
    _ship2->setInputs(key);
}

void Player::unsetShipMove(sf::Keyboard::Key key)
{
    _ship1->unSetInputs(key);
    _ship2->unSetInputs(key);
}

pair<Ship *, Ship *> Player::getShips() const
{
    return (make_pair(_ship1, _ship2));
}