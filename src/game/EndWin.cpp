/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** EndWin
*/

#include "EndWin.hpp"

EndWin::EndWin()
{
    _path.push_back(make_pair("res/endwin", "assets/yoda.png"));
    _index = -1;
    _isFinished = true;
    _isOpen = false;
}

EndWin::~EndWin()
{
}

void EndWin::displayEndWin(sf::RenderWindow *w)
{
    if (_chat.isOpen()) {
        _chat.setDialog();
        _chat.draw(w);
    } else {
        _isOpen = false;
    }
}

void EndWin::reset()
{
    _index = -1;
    _isFinished = true;
    _isOpen = false;
}


void EndWin::enterEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter) {
            _chat.addLine();
        }
    }
}

void EndWin::openEndWin(sf::RenderWindow *w)
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
    displayEndWin(w);
    if (_isOpen == false && (_index == (int)_path.size() - 1)) {
        global_scene = GAME_OVER;
    }
}

