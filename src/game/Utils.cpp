/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Utils
*/

#include "Utils.hpp"

Utils::Utils()
{
}

Utils::~Utils()
{
}

float Utils::vectorMagnitude(sf::Vector2f vector)
{
    float magnitude = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
    return (magnitude);
}

sf::Vector2f Utils::vectorNormalize(sf::Vector2f vector)
{
    float w = vectorMagnitude(vector);
    vector.x /= w;
    vector.y /= w;

    return (vector);
}

sf::Vector2f Utils::rotatePointAroundCenter(sf::Vector2f point, sf::Vector2f center, float angle_rad)
{
    float sin_val = sin(angle_rad);
    float cos_val = cos(angle_rad);

    point.x -= center.x;
    point.y -= center.y;

    float xnew = point.x * cos_val - point.y * sin_val;
    float ynew = point.x * sin_val + point.y * cos_val;

    point.x = xnew + center.x;
    point.y = ynew + center.y;

    return (point);
}

sf::Vector2f Utils::getRandomNormalizedVector()
{
    float randX = (-1.0f + float(rand() % 200 / 100.0f));
    float randY = (-1.0f + float(rand() % 200 / 100.0f));

    return (sf::Vector2f(randX, randY));
}

float Utils::dotProduct(sf::Vector2f vector_a, sf::Vector2f vector_b)
{
    return ((vector_a.x * vector_b.x) + (vector_a.y * vector_b.y));
}

void Utils::posDebug(sf::Vector2f pos, sf::RenderWindow &window)
{
    sf::CircleShape dot;
    dot.setPosition({pos.x - 2, pos.y - 2});
    dot.setFillColor(sf::Color::White);
    dot.setRadius(4.0f);
    window.draw(dot);
}