/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** EntityController
*/

#include "EntityController.hpp"

EntityController::EntityController()
{
    _textures.push_back(new sf::Texture);
    _textures[ASTEROID]->loadFromFile("assets/asteroid1.png");
    _player = new Player;
    _parallax = new Parallax;
    _asteroidClock.restart();
    srand(time(NULL));
    _randTime = 0.4 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 2.0));
}

EntityController::~EntityController()
{
    for (auto iter : _textures)
        delete iter;
    for (auto iter : _asteroid)
        delete iter;
}

void EntityController::drawAll(sf::RenderWindow *w) const
{
    _parallax->drawLayers(w);
    for (auto a : _asteroid)
        w->draw(a->getSprite());
    _player->drawPlayer(w);
}

void EntityController::updateAll()
{
    _parallax->moveLayers();
    updateAsteroids();
}

void EntityController::addAsteroid(sf::Vector2f pos)
{
    _asteroid.push_back(new Asteroid(_textures[ASTEROID], pos, 2 + (rand() % 6)));
}

void EntityController::createRandomAsteroids()
{
    if (_asteroidClock.getElapsedTime().asSeconds() > _randTime) {
        float x = rand() % 1920;
        addAsteroid(sf::Vector2f{x, -500});
        _asteroidClock.restart();
        _randTime = 0.4 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 2.0));
    }
}

void EntityController::updateAsteroids()
{
    createRandomAsteroids();
    for (auto itr : _asteroid) {
        itr->moveAsteroid();
        itr->rotateAsteroid();
    }
    destroyAsteroids();
}

void EntityController::destroyAsteroids()
{
    for (size_t i = 0; i < _asteroid.size(); i++) {
        if (_asteroid[i]->getPos().y >= 1250) {
            _asteroid.erase(_asteroid.begin() + i);
        }
    }
}