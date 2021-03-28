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

float Utils::vectorSize(sf::Vector2f vector1,sf::Vector2f vector2)
{
    float magnitude = sqrt(pow(vector2.x - vector1.x, 2) + pow(vector2.y - vector1.y, 2));
    return (magnitude);
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

bool Utils::segmentIntersectsRectangle(const sf::FloatRect &rect,
    const sf::Vector2f &a_p1, const sf::Vector2f &a_p2)
{
    // Find min and max X for the segment
    auto minX = std::min(a_p1.x, a_p2.x);
    auto maxX = std::max(a_p1.x, a_p2.x);

    // Find the intersection of the segment's and rectangle's x-projections
    if (maxX > rect.left + rect.width) {
        maxX = rect.left + rect.width;
    }

    if (minX < rect.left) {
        minX = rect.left;
    }

    // If Y-projections do not intersect then there's no intersection
    if (minX > maxX) { return false; }

    // Find corresponding min and max Y for min and max X we found before
    auto minY = a_p1.y;
    auto maxY = a_p2.y;

    auto dx = a_p2.x - a_p1.x;
    if (std::abs(dx) > 0.0000001f) {
        auto k = (a_p2.y - a_p1.y) / dx;
        auto b = a_p1.y - k * a_p1.x;
        minY = k * minX + b;
        maxY = k * maxX + b;
    }

    if (minY > maxY) {
        std::swap(minY, maxY);
    }

    // Find the intersection of the segment's and rectangle's y-projections
    if (maxY > rect.top + rect.height) {
        maxY = rect.top + rect.height;
    }

    if (minY < rect.top) {
        minY = rect.top;
    }

    // If Y-projections do not intersect then there's no intersection
    if (minY > maxY) { return false; }
    return true;
}