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

class Entity {
    public:
        Entity(sf::Texture *texture, sf::Vector2f pos);
        ~Entity();

        sf::Sprite &getSprite() const;
    protected:
        sf::Texture *_texture;
        sf::Sprite *_sprite;
        sf::Vector2f _pos;
    private:
};

#endif /* !ENTITY_HPP_ */
