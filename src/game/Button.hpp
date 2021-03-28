/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "Entity.hpp"
#include <fstream>

using namespace std;

class Button : public Entity {
    public:
        Button(sf::Texture *texture, sf::Vector2f pos, string filepath, string language);
        ~Button();

        void setFont(sf::Font &font);
        void drawButton(sf::RenderWindow *w) const;
        void hoverButton(sf::RenderWindow *w);
        sf::Color getColor() const;
        void setColor(sf::Color color);
        void btnHover(sf::RenderWindow *w);
        void loadTxt();
        void setLang(string &lang);

    protected:
    private:
        sf::Uint8 _alpha;
        sf::Text _btnText;
        string _lang;
        string _path;
};

#endif /* !BUTTON_HPP_ */
