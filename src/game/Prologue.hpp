/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Prologue
*/

#ifndef PROLOGUE_HPP_
#define PROLOGUE_HPP_

#include "EntityController.hpp"
#include "ChatBox.hpp"

class Prologue {
    public:
        Prologue();
        ~Prologue();

        void openPrologue(sf::RenderWindow *w);
        void displayPrologue(sf::RenderWindow *w);
        void enterEvent(sf::Event event);
    protected:
    private:
        ChatBox _chat;
        bool _isFinished;
        vector<pair<string, bool>> _path;
        bool _isOpen;
        int _index;
};

#endif /* !PROLOGUE_HPP_ */
