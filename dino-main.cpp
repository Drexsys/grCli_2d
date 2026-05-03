//
// Created by drexsys on 02.05.26.
//

#include "dino-src/Menu.h"
#include "dino-src/Game.h"

#include<ncurses.h>

constexpr unsigned int FPS = 1000000 / 30;

void initNurses() {
    // Ініціалізація ncurses
    initscr();
    cbreak();           // Вимкнути буферизацію
    noecho();           // Не показувати натиснуті клавіші
    keypad(stdscr, TRUE); // Включити спеціальні клавіші
    nodelay(stdscr, TRUE); // Неблокуючий ввід
}

int main() {
    initNurses();

    auto screen = new Screen(80, 24, FPS);
    auto menu = new Menu(screen);
    auto game = new Game(screen);

    while (true) {
        if (menu->getIsMenu()) {
            if (menu->run())
                menu->setIsMenu(false);
            else
                break;
        } else {
            game->run();
            menu->setIsMenu(true);
        }
    }

    delete screen;
    delete menu;
    delete game;

    endwin();

    return 0;
}
