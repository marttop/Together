/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Parallax
*/

#include "Parallax.hpp"

Parallax::Parallax()
{
    _layerTextures[NEBULA_AQUA_PINK].loadFromFile("assets/nebula_aqua_pink.png");
    _layerTextures[NEBULA_BLUE].loadFromFile("assets/nebula_blue.png");
    _layerTextures[NEBULA_RED].loadFromFile("assets/nebula_red.png");
    _layerTextures[SMALL_STARS1].loadFromFile("assets/small_stars1.png");
    _layerTextures[SMALL_STARS2].loadFromFile("assets/small_stars2.png");
    _layerTextures[BIG_STARS1].loadFromFile("assets/big_stars1.png");
    _layerTextures[BIG_STARS2].loadFromFile("assets/big_stars2.png");
    addLayer(1.0, NEBULA_AQUA_PINK, false);
    addLayer(1.0, NEBULA_BLUE, true);
    addLayer(1.0, NEBULA_RED, false);
    addLayer(2.0, BIG_STARS1, true);
    addLayer(2.0, SMALL_STARS1, true);
    addLayer(3.0, BIG_STARS2, true);
    addLayer(3.0, SMALL_STARS2, true);
}

Parallax::~Parallax()
{
}

void Parallax::addLayer(float speed, Layers type, bool active)
{
    _layersVec.push_back(
        make_pair(
            speed,
            make_pair(
                new Layer(&_layerTextures[type], sf::Vector2f{0, 0}, active),
                new Layer(&_layerTextures[type], sf::Vector2f{0, -float(_layerTextures[type].getSize().y)}, active)
            )
        )
    );
}

void Parallax::moveLayers()
{
    for (auto iter : _layersVec) {
        if (iter.second.first->getElapsedTime() > 0.05 && iter.second.first->isActive() == true) {
            iter.second.first->setPos(sf::Vector2f(iter.second.first->getPos().x, iter.second.first->getPos().y + iter.first));
            iter.second.second->setPos(sf::Vector2f(iter.second.second->getPos().x, iter.second.second->getPos().y + iter.first));
            if (iter.second.first->getPos().y >= iter.second.first->getSize().y)
                iter.second.first->setPos(sf::Vector2f(iter.second.first->getPos().x, iter.second.first->getPos().y - iter.second.first->getSize().y * 2));
            if (iter.second.second->getPos().y >= iter.second.second->getSize().y)
                iter.second.second->setPos(sf::Vector2f(iter.second.second->getPos().x, iter.second.second->getPos().y - iter.second.second->getSize().y * 2));
            iter.second.first->restartClock();
            iter.second.second->restartClock();
        }
    }
}


void Parallax::drawLayers(sf::RenderWindow *w)
{
    for (auto iter : _layersVec) {
        if (iter.second.first->isActive() == true) {
            w->draw(iter.second.first->getSprite());
            w->draw(iter.second.second->getSprite());
        }
    }
}