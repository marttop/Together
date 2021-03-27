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
    try {
        Game game("Together", 1920, 1080);
        game.run();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}