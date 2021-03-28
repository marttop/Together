/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Particles
*/

#ifndef PARTICLES_HPP_
#define PARTICLES_HPP_

#include "Utils.hpp"

class Particle
{
    public:
        Particle(sf::Color startColor, sf::Color endColor, int life, sf::Vector2f direction, sf::Vector2f randomDirection);
        ~Particle();

        void setDirection(sf::Vector2f direction);
        void setRandomDirection(sf::Vector2f direction);
        void setPosition(sf::Vector2f position);
        void setColor(sf::Color color);
        void setTimeStep(float timeStep);
        float getTimeStep();
        int getLife();
        sf::VertexArray getParticle();
        sf::Color getStartColor();
        sf::Color getEndColor();
        sf::Vector2f getPosition();
        sf::Vector2f getDirection();
        sf::Vector2f getRandomDirection();

    protected:
    private:
        sf::Color _startColor;
        sf::Color _endColor;
        sf::VertexArray _part;
        sf::Vector2f _direction;
        sf::Vector2f _randomDirection;
        int _life;
        float _timeStep;
        bool _dead;
};

class ParticleSystem
{
    public:
        ParticleSystem();
        ~ParticleSystem();

        void update(sf::Vector2f offset, sf::Vector2f direction, sf::Vector2f position, sf::Color startColor, sf::Color endColor, int life, int isRand);
        void drawParticles(sf::RenderWindow *window);

    protected:
    private:
        Particle *createParticle(sf::Color startColor, sf::Color endColor, sf::Vector2f offset, sf::Vector2f direction, sf::Vector2f randomDirection, sf::Vector2f position, int life);
        sf::Color rgbInterpolation(sf::Color startColor, float timeStep, sf::Color endColor);

        std::vector<Particle *> _particles;
        Utils *_utils;
};

#endif /* !PARTICULES_HPP_ */