/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** ChatBox
*/

#ifndef CHATBOX_HPP_
#define CHATBOX_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

class ChatBox {
    public:
        ChatBox();
        ~ChatBox();
        void readMessage(const std::string &msgPath);
        char readLetter();
        std::string readLine(std::string msg);
        void addLine();
        void draw(sf::RenderWindow *w);
        std::vector<sf::Text> getDialog() const;
        sf::RectangleShape getBox() const;
        void setDialog();
    private:
        sf::Clock textClock;
        sf::Font _font;
        sf::Texture _texture;
        sf::Sprite _sprite;
        std::vector<sf::Text> _dialog;
        std::vector<std::string> _msg;
        sf::RectangleShape _box;
        std::string lang;
        std::ifstream _file;
        size_t _lines;
        bool isOpen;
        bool newline;
        bool read;
        bool allLine;
};

#endif /* !CHATBOX_HPP_ */
