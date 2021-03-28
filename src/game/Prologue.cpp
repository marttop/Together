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
    _path.push_back(make_pair("res/prologue", false));
    _path.push_back(make_pair("res/prologue1", false));
    _path.push_back(make_pair("res/prologue2", false));
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
        _chat.setLanguage(global_language);
        _isOpen = true;
        _index++;
        _chat.readMessage(_path[_index].first);
        _chat.loadSprite("assets/sheldon.png");
    }
    displayPrologue(w);
}