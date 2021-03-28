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

        sf::Vector2f rotatePointAroundCenter(sf::Vector2f point, sf::Vector2f center, float angle_rad);
        sf::Vector2f getRandomNormalizedVector();
        float dotProduct(sf::Vector2f vector_a, sf::Vector2f vector_b);
        void posDebug(sf::Vector2f pos, sf::RenderWindow &window);
        bool segmentIntersectsRectangle(const sf::FloatRect &rect, const sf::Vector2f &a_p1, const sf::Vector2f &a_p2);
        float vectorSize(sf::Vector2f vector1,sf::Vector2f vector2);
        float vectorMagnitude(sf::Vector2f vector);
        sf::Vector2f vectorNormalize(sf::Vector2f vector);

    protected:
    private:
};

#endif /* !UTILS_HPP_ */