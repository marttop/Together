/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Prologue
*/

#include "Prologue.hpp"

Prologue::Prologue()
{
    _path.push_back(make_pair("res/prologue", "assets/damien.png"));
    _path.push_back(make_pair("res/prologue1", "assets/stargate.png"));
    _path.push_back(make_pair("res/prologue2", "assets/startrek.png"));
    _path.push_back(make_pair("res/prologue3", "assets/damien.png"));
    _path.push_back(make_pair("res/prologue4", "assets/startrek.png"));
    _path.push_back(make_pair("res/prologue5", "assets/stargate.png"));
    _path.push_back(make_pair("res/prologue6", "assets/startrek.png"));
    _path.push_back(make_pair("res/prologue7", "assets/stargate.png"));
    _index = -1;
    _isFinished = true;
    _isOpen = false;
}

Prologue::~Prologue()
{
}

void Prologue::reset()
{
    _index = -1;
    _isFinished = true;
    _isOpen = false;
}

void Prologue::displayPrologue(sf::RenderWindow *w)
{
    if (_chat.isOpen()) {
        _chat.setDialog();
        _chat.draw(w);
    } else {
        _isOpen = false;
    }
}

void Prologue::enterEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter) {
            _chat.addLine();
        }
    }
}

void Prologue::openPrologue(sf::RenderWindow *w)
{
    if (_isOpen == false && (_index < (int)_path.size() - 1)) {
        sf::IntRect r = w->getViewport(w->getView());
        _chat.setLanguage(global_language);
        _isOpen = true;
        _index++;
        _chat.readMessage(_path[_index].first);
        _chat.loadSprite(_path[_index].second);
        _chat.setPositions(r);
    }
    displayPrologue(w);
    if (_isOpen == false && (_index == (int)_path.size() - 1)) {
        global_scene = GAME;
        mainClock.restart();
    }
}