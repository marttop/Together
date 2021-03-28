/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Layer.hpp"
#include "EntityController.hpp"
#include "Button.hpp"

using namespace std;

class Menu {
    public:
        Menu();
        ~Menu();
        void displayMenu(sf::RenderWindow *w);
        void menuAnimation();
        void clickButton(sf::RenderWindow *w);
        void releaseButton(sf::RenderWindow *w);
        void updateMenuLang();
    protected:
    private:
        sf::Font _font;
        sf::Texture _bckgrTexture;
        sf::Texture _btnTexture;
        sf::Texture _smallBtnTexture;
        Layer *_background;
        sf::Text _title;
        vector<Button *> _buttons;
        sf::Clock _clock;
};

#endif /* !MENU_HPP_ */
