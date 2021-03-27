/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Layer
*/

#include "Layer.hpp"

Layer::Layer(sf::Texture *texture, sf::Vector2f pos, bool active) : Entity(texture, pos)
{
    _isActive = active;
}

Layer::~Layer()
{
}

void Layer::setActive(bool activation)
{
    _isActive = activation;
}

bool Layer::isActive() const
{
    return (_isActive);
}