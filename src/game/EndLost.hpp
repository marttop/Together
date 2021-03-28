/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** EndLost
*/

#ifndef ENDLOST_HPP_
#define ENDLOST_HPP_

#include "EntityController.hpp"
#include "ChatBox.hpp"

class EndLost {
    public:
        EndLost();
        ~EndLost();

        void openEndLost(sf::RenderWindow *w);
        void displayEndLost(sf::RenderWindow *w);
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

#endif /* !ENDLOST_HPP_ */
