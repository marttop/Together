/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Ship
*/

/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Ship
*/

#ifndef SHIP_HPP_
#define SHIP_HPP_

class Ship;

#include "Entity.hpp"
#include "ShipHud.hpp"
#include "Ammo.hpp"
#include "EntityController.hpp"


using namespace std;

class Ship : public Entity {
    public:
        Ship(sf::Texture *texture, sf::Vector2f pos, sf::IntRect rectangle, sf::Keyboard::Key *keys, sf::IntRect bulletRect);
        ~Ship();

        void update(sf::Color startColor, sf::Color endColor);
        void setInputs(sf::Keyboard::Key key);
        void unSetInputs(sf::Keyboard::Key key);
        void drawParticles(sf::RenderWindow *w);
        void checkIfHit();
        sf::Text getName() const;
        sf::RectangleShape getBox() const;
        sf::RectangleShape getBar() const;
        sf::RectangleShape getHpRect() const;
        ShipHud *getHud() const;
        float getHpShip() const;
        void setHpShip(float newHp);
        void drawAmmos(sf::RenderWindow *w);
        Ammo &getAmmos(int i);
        float getSpeed();
        void setSpeed(float speed);
        void setCanShoot(bool shoot);
        void hitMyAss();
        bool isHit() const;
        void blink();
        void restartClock();

    protected:
    private:
        void moveShipRect();

        sf::Keyboard::Key *_keys;
        float _speed;
        bool *_inputs;
        int _rectOffset;
        sf::IntRect _rect;
        sf::Texture *_ammoTexture;

        bool _isHit;
        ShipHud *_hud;
        Ammo *_ammos[2];
        float _hp;
        bool _canShoot;


        bool _blink;
        sf::Clock _clock;
        sf::Clock _immunity;
        sf::Vector2f _savePos;
};

#endif /* !SHIP_HPP_ */