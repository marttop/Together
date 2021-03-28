/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_


#include "EntityController.hpp"
#include "Ship.hpp"
#include "SFML/OpenGL.hpp"
#include <fstream>

class Player {
    public:
        Player();
        ~Player();
        sf::Sprite &getSprite(int i) const;
        void drawPlayer(sf::RenderWindow *w);
        void update();
        void setShipMove(sf::Keyboard::Key key);
        void unsetShipMove(sf::Keyboard::Key key);
        string loadNames(string filepath);
        pair<Ship *, Ship *> getShips() const;

    protected:
    private:
        sf::Texture _shipTextures;
        Ship *_ship1;
        Ship *_ship2;
};

#endif /* !PLAYER_HPP_ */