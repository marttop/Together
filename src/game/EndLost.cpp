/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** EndLost
*/

#include "EndLost.hpp"

EndLost::EndLost()
{
    _path.push_back(make_pair("res/endlost", "assets/damien.png"));
    _index = -1;
    _isFinished = true;
    _isOpen = false;
}

EndLost::~EndLost()
{
}

void EndLost::displayEndLost(sf::RenderWindow *w)
{
    if (_chat.isOpen()) {
        _chat.setDialog();
        _chat.draw(w);
    } else {
        _isOpen = false;
    }
}

void EndLost::reset()
{
    _index = -1;
    _isFinished = true;
    _isOpen = false;
}


void EndLost::enterEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter) {
            _chat.addLine();
        }
    }
}

void EndLost::openEndLost(sf::RenderWindow *w)
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
    displayEndLost(w);
    if (_isOpen == false && (_index == (int)_path.size() - 1)) {
        global_scene = GAME_OVER;
    }
}
