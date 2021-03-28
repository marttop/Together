/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** EndWin
*/

#ifndef ENDWIN_HPP_
#define ENDWIN_HPP_

#include "EntityController.hpp"
#include "ChatBox.hpp"

class EndWin {
    public:
        EndWin();
        ~EndWin();

        void openEndWin(sf::RenderWindow *w);
        void displayEndWin(sf::RenderWindow *w);
        void enterEvent(sf::Event event);
        void reset();
    protected:
    private:
        ChatBox _chat;
        bool _isFinished;
        vector<pair<string, string>> _path;
        bool _isOpen;
        int _index;
};

#endif /* !ENDWIN_HPP_ */
