/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Particle
*/

#include "Particles.hpp"

Particle::Particle(sf::Color startColor, sf::Color endColor, int life, sf::Vector2f direction, sf::Vector2f randomDirection)
{
    _part = sf::VertexArray(sf::Points, 1);
    _life = life;
    _startColor = startColor;
    _endColor = endColor;
    _timeStep = 0.0f;
    _dead = false;
    _direction = direction;
    _randomDirection = randomDirection;
}

Particle::~Particle()
{
}

void Particle::setDirection(sf::Vector2f direction)
{
    _direction = direction;
}

void Particle::setRandomDirection(sf::Vector2f randomDirection)
{
    _randomDirection = randomDirection;
}

void Particle::setPosition(sf::Vector2f position)
{
    _part[0].position = position;
}

void Particle::setColor(sf::Color color)
{
    _part[0].color = color;
}

void Particle::setTimeStep(float timeStep)
{
    _timeStep = timeStep;
}

float Particle::getTimeStep()
{
    return (_timeStep);
}

int Particle::getLife()
{
    return (_life);
}

sf::Color Particle::getStartColor()
{
    return (_startColor);
}

sf::Color Particle::getEndColor()
{
    return (_endColor);
}

sf::Vector2f Particle::getPosition()
{
    return (_part[0].position);
}

sf::Vector2f Particle::getDirection()
{
    return (_direction);
}

sf::Vector2f Particle::getRandomDirection()
{
    return (_randomDirection);
}

sf::VertexArray Particle::getParticle()
{
    return (_part);
}

ParticleSystem::ParticleSystem()
{
    _utils = new Utils();
}

ParticleSystem::~ParticleSystem()
{
    delete _utils;
}

sf::Color ParticleSystem::rgbInterpolation(sf::Color startColor, float timeStep, sf::Color endColor)
{
	sf::Color finalColor;

	finalColor.r = startColor.r + (endColor.r - startColor.r) * timeStep;
	finalColor.g = startColor.g + (endColor.g - startColor.g) * timeStep;
	finalColor.b = startColor.b + (endColor.b - startColor.b) * timeStep;
	finalColor.a = startColor.a + (endColor.a - startColor.a) * timeStep;

	return (finalColor);
}

Particle *ParticleSystem::createParticle(sf::Color startColor, sf::Color endColor, sf::Vector2f offset, sf::Vector2f direction, sf::Vector2f randomDirection, sf::Vector2f position, int life)
{
    Particle *particle = new Particle(startColor, endColor, life, direction, randomDirection);

    position.x += offset.x;
    position.y += offset.y;
    float angleDirection = atan2((direction.y - position.y), (direction.x - position.x));
    direction = sf::Vector2f(cos(angleDirection), sin(angleDirection));
    float magnitude = _utils->vectorMagnitude(direction);
    particle->setDirection(sf::Vector2f(direction.x / magnitude, direction.y / magnitude));
    particle->setPosition(position);
    particle->setColor(rgbInterpolation(startColor, particle->getTimeStep(), endColor));

    return (particle);
}

void ParticleSystem::update(sf::Vector2f offset, sf::Vector2f direction, sf::Vector2f position, sf::Color startColor, sf::Color endColor, int life, int isRand)
{
    int number = _utils->vectorMagnitude(sf::Vector2f(direction.x, direction.y));
    if (number == 0) number = 1;
    else if (number > 3) number = 3;

    int speed = _utils->vectorMagnitude(sf::Vector2f(direction.x, direction.y)) / 2;
    if (speed == 0) speed = 1;
    else if (speed > 5) speed = 5;

    int tmpLife = life;
    for (int i = 0, value = 10; i != number; i++) {
        if (isRand == 1) tmpLife = rand() % life;
        _particles.push_back(createParticle(startColor, endColor, sf::Vector2f{rand() % (value - value / 3) + offset.x, rand() % (value - value / 3) + offset.y}, direction, _utils->getRandomNormalizedVector(), position, tmpLife));
        if (isRand == 1) tmpLife = rand() % life;
        _particles.push_back(createParticle(startColor, endColor, sf::Vector2f{-(rand() % (value - value / 3) + offset.x), -(rand() % (value - value / 3) + offset.y)}, direction, _utils->getRandomNormalizedVector(), position, tmpLife));
        if (isRand == 1) tmpLife = rand() % life;
        _particles.push_back(createParticle(startColor, endColor, sf::Vector2f{rand() % (value - value / 3) + offset.x, -(rand() % (value - value / 3) + offset.y)}, direction, _utils->getRandomNormalizedVector(), position, tmpLife));
        if (isRand == 1) tmpLife = rand() % life;
        _particles.push_back(createParticle(startColor, endColor, sf::Vector2f{-(rand() % (value - value / 3) + offset.x), rand() % (value - value / 3) + offset.y}, direction, _utils->getRandomNormalizedVector(), position, tmpLife));
    }
    for (size_t i = 0; i < _particles.size(); i++) {
        _particles[i]->setTimeStep(_particles[i]->getTimeStep() + (1.0f / _particles[i]->getLife()));
        sf::Color resColor = rgbInterpolation(_particles[i]->getStartColor(), _particles[i]->getTimeStep(), _particles[i]->getEndColor());
        _particles[i]->setColor(resColor);
        _particles[i]->setPosition(
            sf::Vector2f{_particles[i]->getPosition().x + (_particles[i]->getDirection().x * (_particles[i]->getRandomDirection().x * speed)),
            _particles[i]->getPosition().y + (_particles[i]->getDirection().y * speed)}
        );
        if (_particles[i]->getTimeStep() > 1.0f) {
            delete _particles[i];
            _particles.erase(_particles.begin() + i);
        }
    }
}

void ParticleSystem::drawParticles(sf::RenderWindow *window)
{
    for (size_t i = 0; i < _particles.size(); i++) {
        window->draw(_particles[i]->getParticle());
    }
}