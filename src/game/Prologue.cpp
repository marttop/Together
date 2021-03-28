/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Prologue
*/

#include <iostream>
#include "Prologue.hpp"

Prologue::Prologue()
{
    _path.push_back(make_pair("res/prologue", "assets/yoda.png"));
    _path.push_back(make_pair("res/prologue1", "assets/vador.png"));
    _path.push_back(make_pair("res/prologue2", "assets/luke.png"));
    _path.push_back(make_pair("res/prologue3", "assets/yoda.png"));
    _path.push_back(make_pair("res/prologue4", "assets/luke.png"));
    _path.push_back(make_pair("res/prologue5", "assets/vador.png"));
    _path.push_back(make_pair("res/prologue6", "assets/luke.png"));
    _path.push_back(make_pair("res/prologue7", "assets/vador.png"));
    _index = -1;
    _isFinished = true;
    _isOpen = false;
}

Prologue::~Prologue()
{
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
}