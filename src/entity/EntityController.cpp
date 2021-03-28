/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** EntityController
*/

#include "EntityController.hpp"

EntityController::EntityController(Player *player)
{
    srand(time(NULL));
    _textures.push_back(new sf::Texture);
    _textures[ASTEROID]->loadFromFile("assets/asteroid1.png");
    _textures.push_back(new sf::Texture);
    _textures[NYANCAT]->loadFromFile("assets/nyan.png");
    _player = player;
    _parallax = new Parallax;
    _asteroidClock.restart();
    _nyanClock.restart();
    _randTimeAsteroids = 0.4 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 2.0));
    _randTimeNyan = 5.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 10.0));
}

EntityController::~EntityController()
{
    for (auto iter : _textures)
        delete iter;
    for (auto iter : _asteroid)
        delete iter;
    delete _parallax;
}

void EntityController::drawAll(sf::RenderWindow *w) const
{
    _parallax->drawLayers(w);
    if (global_scene == GAME) {
        for (auto a : _nyanCat) {
            a->drawParticles(w);
            w->draw(a->getSprite());
        }
        for (auto a : _asteroid) {
            a->drawParticles(w);
            w->draw(a->getSprite());
        }
        _player->drawPlayer(w);
    }
}

void EntityController::updateAll()
{
    _parallax->moveLayers();
    updatePlayer();
    if (global_scene == GAME) {
        updateAsteroids();
        updateNyanCat();
    }
    else if (global_scene == GAME_OVER || global_scene == GAME_WON) {
        pair<Ship *, Ship *> p = _player->getShips();
        p.first->setHpShip(100);
        p.second->setHpShip(100);
        p.first->getHud()->updateHp(p.first->getHpShip());
        p.second->getHud()->updateHp(p.second->getHpShip());
    }
}

void EntityController::addAsteroid(sf::Vector2f pos)
{
    _asteroid.push_back(new Asteroid(_textures[ASTEROID], pos, 2 + (rand() % 6)));
}

void EntityController::addNyan(sf::Vector2f pos)
{
    _nyanCat.push_back(new NyanCat(_textures[NYANCAT], pos, 6 + (rand() % 4)));
}

void EntityController::checkShooting()
{
    int index = 0;
    for (auto itr : _asteroid) {
        vector<Bullet *> *a = &this->_player->getShip(0).getAmmos(0).getLasers();
        vector<Bullet *> *b = &this->_player->getShip(0).getAmmos(1).getLasers();
        vector<Bullet *> *c = &this->_player->getShip(1).getAmmos(0).getLasers();
        vector<Bullet *> *d = &this->_player->getShip(1).getAmmos(1).getLasers();

        sf::Vector2f scale = itr->getscale();

        for (size_t i = 0; i < a->size(); i++) {
            if (itr->isColliding(a->at(i)) || itr->isColliding(b->at(i))) {
                if (scale.x <= 0.15f) {
                    _asteroid.erase(_asteroid.begin() + index);
                }
                else {
                    itr->reduceScale();
                }
                a->erase(a->begin() + i);
                b->erase(b->begin() + i);
                break;
            }
        }
        for (size_t i = 0; i < c->size(); i++) {
            if (itr->isColliding(c->at(i)) || itr->isColliding(d->at(i))) {
                if (scale.x <= 0.15f) {
                    _asteroid.erase(_asteroid.begin() + index);
                }
                else {
                    itr->reduceScale();
                }
                c->erase(c->begin() + i);
                d->erase(d->begin() + i);
                break;
            }
        }
        index++;
    }
}

void EntityController::createRandomAsteroids()
{
    bool isSpawned = false;
    if (_asteroidClock.getElapsedTime().asSeconds() > _randTimeAsteroids) {
        for (size_t i = 0; !isSpawned; ) {
            float x = rand() % 1920;
            i = 0;
            addAsteroid(sf::Vector2f{x, -250});
            _asteroidClock.restart();
            _randTimeAsteroids = 0.4 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 2.0));
            for (auto itr : _asteroid) {
                if (itr != _asteroid.back() && !itr->isColliding(_asteroid.back())) {
                    i++;
                }
            }
            if (i + 1 == _asteroid.size())
                isSpawned = true;
            else
                _asteroid.pop_back();
        }
    }
}

void EntityController::createRandomNyanCat()
{
    if (_nyanClock.getElapsedTime().asSeconds() > _randTimeNyan) {
        float x = rand() % 1920;
        addNyan(sf::Vector2f{x, -250});
        _nyanClock.restart();
        _randTimeNyan = 5.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 10.0));
    }
}

void EntityController::updatePlayer()
{
    _player->update();
    if (global_scene == GAME_OVER || global_scene == GAME_WON)
        return;
    int i = 0;
    pair<Ship *, Ship *> p = _player->getShips();
    for (auto itr : _asteroid) {

        sf::Vector2f scale = itr->getscale();

        if (itr->isColliding((Entity *)p.first) && !p.first->isHit()) {
            if (scale.x <= 0.15f) {
                _asteroid.erase(_asteroid.begin() + i);
            }
            else
                itr->reduceScale();
            p.first->hitMyAss();
            p.first->setHpShip(p.first->getHpShip() - 10);
            p.first->getHud()->updateHp(p.first->getHpShip());
            if (p.first->getHpShip() <= 0) {
                gameOver = true;
                global_scene = GAME_OVER;
            }
        }

        if (itr->isColliding((Entity *)p.second) && !p.second->isHit()) {
            if (scale.x <= 0.15f) {
                _asteroid.erase(_asteroid.begin() + i);
            }
            else
                itr->reduceScale();
            p.second->hitMyAss();
            p.second->setHpShip(p.second->getHpShip() - 10);
            p.second->getHud()->updateHp(p.second->getHpShip());
            if (p.second->getHpShip() <= 0) {
                gameOver = true;
                global_scene = GAME_OVER;
            }
        }
        i++;
    }
    for (auto itr : _nyanCat) {
        if (_player->getLink() == true && _utils.segmentIntersectsRectangle(itr->getSprite().getGlobalBounds(), _player->getLineVectors(true), _player->getLineVectors(false)))
            if (itr->getSpeed() > 0){
                itr->setSpeed(itr->getSpeed() * -1);
                itr->setRotation(180);
            }
    }
    checkShooting();
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

void EntityController::updateNyanCat()
{
    createRandomNyanCat();
    for (auto itr : _nyanCat)
        itr->moveNyanCat();
    destroyNyanCat();
}

void EntityController::destroyAsteroids()
{
    for (size_t i = 0; i < _asteroid.size(); i++) {
        if (_asteroid[i]->getPos().y >= 2000 || _asteroid[i]->getPos().y <= -500) {
            _asteroid.erase(_asteroid.begin() + i);
        }
    }
}


void EntityController::destroyNyanCat()
{
    for (size_t i = 0; i < _nyanCat.size(); i++) {
        if (_nyanCat[i]->getPos().y >= 2000 || _nyanCat[i]->getPos().y <= -1000) {
            _nyanCat.erase(_nyanCat.begin() + i);
        }
    }
}

void EntityController::deleteAsteroids()
{
    for (size_t i = 0; i < _asteroid.size(); i++) {
        _asteroid.pop_back();
    }
    _asteroid.clear();
}

void EntityController::deleteNyanCat()
{
    for (size_t i = 0; i < _nyanCat.size(); i++) {
        _nyanCat.pop_back();
    }
    _nyanCat.clear();
}