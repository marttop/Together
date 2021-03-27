/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <math.h>

class Utils {
    public:
        Utils();
        ~Utils();

        float vectorMagnitude(sf::Vector2f vector);
        sf::Vector2f vectorNormalize(sf::Vector2f vector);
        sf::Vector2f rotatePointAroundCenter(sf::Vector2f point, sf::Vector2f center, float angle_rad);
        sf::Vector2f getRandomNormalizedVector();
        float dotProduct(sf::Vector2f vector_a, sf::Vector2f vector_b);

    protected:
    private:
};

#endif /* !UTILS_HPP_ */