/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** NyanCat
*/

#ifndef NYANCAT_HPP_
#define NYANCAT_HPP_

#include "Enemy.hpp"

class NyanCat : public Enemy  {
    public:
        NyanCat(sf::Texture *texture, sf::Vector2f pos, float speed);
        ~NyanCat();

        void moveNyanCat();
        void moveRect();

    protected:
    private:
        sf::Clock _rectClock;
        sf::IntRect _rect;
        sf::Vector2f _partPos;
        bool _touched;
        sf::Sound _sound;
        sf::SoundBuffer _soundBuffer;
};

#endif /* !NYANCAT_HPP_ */