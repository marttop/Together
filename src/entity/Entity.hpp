/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>

#include "Particles.hpp"

class ParticleSystem;

class Entity {
    public:
        Entity(sf::Texture *texture, sf::Vector2f pos);
        ~Entity();

        sf::Sprite &getSprite() const;
        float getElapsedTime() const;
        sf::Vector2f getPos() const;
        sf::Vector2f getSize() const;
        void setPos(sf::Vector2f pos);
        void restartClock();
        void setRotation(float angle);
        void drawParticles(sf::RenderWindow *w);
        bool isMouseOnSprite(sf::RenderWindow *w) const;
        bool isColliding(Entity *other);
        void setColor(sf::Color color);
    protected:
        sf::Texture *_texture;
        sf::Sprite *_sprite;
        sf::Vector2f _pos;
        sf::Clock _clock;
        ParticleSystem *_particleSystem;
    private:
};

#endif /* !ENTITY_HPP_ */
