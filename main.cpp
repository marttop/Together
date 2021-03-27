/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** main
*/

#include <iostream>
#include "Game.hpp"

int main()
{
    Game game("SFML", 800, 600);
    while (1) {
        game.handleEvents();
        game.clear();
        game.display();
    }

}