/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** NyanCat
*/

#include "NyanCat.hpp"

NyanCat::NyanCat(sf::Texture *texture, sf::Vector2f pos, float speed) : Enemy(texture, pos, speed)
{
    _particleSystem = new ParticleSystem();
    _rectClock.restart();
    _rect = sf::IntRect{0, 0, 66, 30};
    _sprite->setTextureRect(_rect);
    sf::Vector2u origin = sf::Vector2u{(unsigned int)_sprite->getGlobalBounds().width, (unsigned int)_sprite->getGlobalBounds().height};
    _sprite->setOrigin(sf::Vector2f{(float)origin.x / 2, (float)origin.y / 2});
    _sprite->setScale(sf::Vector2f{3.0, 3.0});
    _sprite->setRotation(90);
    _touched = false;
    _soundBuffer.loadFromFile("audio/nyan.ogg");
    _sound.setBuffer(_soundBuffer);
    _sound.setVolume(50.0);
    _sound.play();
}

NyanCat::~NyanCat()
{
    _sound.stop();
}

void NyanCat::moveNyanCat()
{
    if (_speed < 0 && _touched == false) _touched = true;
    if (getElapsedTime() > 0.01) {
        sf::Vector2f pos = getSprite().getPosition();
        setPos(sf::Vector2f{pos.x, pos.y + _speed});
        _clock.restart();
        moveRect();
        if (_touched == false)
            _particleSystem->update(sf::Vector2f{float(-10 + rand() % 10), 0},  sf::Vector2f{_pos.x, _pos.y - 60}, sf::Vector2f{_pos.x, pos.y - 50}, sf::Color{255, 120, 120, 255}, sf::Color{255, 255, 255, 0}, 100, 1);
        else _particleSystem->update(sf::Vector2f{float(-10 + rand() % 10), 0},  sf::Vector2f{_pos.x, _pos.y + 60}, sf::Vector2f{_pos.x, pos.y + 50}, sf::Color{255, 120, 120, 255}, sf::Color{255, 255, 255, 0}, 100, 1);
    }
}


void NyanCat::moveRect()
{
    if (_rectClock.getElapsedTime().asSeconds() > 0.05) {
        if (_rect.left < 132)
            _rect.left += 66;
        else if (_rect.left == 132 && _rect.top < 60) {
            _rect.left = 0;
            _rect.top += 30;
        }
        else if (_rect.left == 132 && _rect.top == 60) {
            _rect.left = 0;
            _rect.top = 0;
        }
        _sprite->setTextureRect(_rect);
        _rectClock.restart();
    }
}