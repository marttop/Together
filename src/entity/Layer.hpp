/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Layer
*/

#ifndef LAYER_HPP_
#define LAYER_HPP_

#include "Entity.hpp"

class Layer : public Entity {
    public:
        Layer(sf::Texture *texture, sf::Vector2f pos, bool active);
        ~Layer();

        void setActive(bool activation);
        void setColor(sf::Color color);
        sf::Color getColor() const;
        bool isActive() const;

    protected:
    private:
        bool _isActive;
};

#endif /* !LAYER_HPP_ */