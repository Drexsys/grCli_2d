//
// Created by drexsys on 02.05.26.
//

#include "dino-src/Menu.h"

//#include <iostream>
#include<ncurses.h>

constexpr unsigned int FPS = 1000000 / 30;

Screen* initScreen() {
//    short width, height;

  //  std::cout << "Enter screen width and height:" << std::endl;
    //std::cin >> width >> height;

    return new Screen(24, 80, FPS);
}

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

    auto screen = initScreen();
    auto menu = new Menu(screen);

    while (true) {
        if (menu->getIsMenu()) {
            if (menu->run())
                menu->setIsMenu(true);
            else
                break;
        }
    }

    delete screen;
    delete menu;

    endwin();

    return 0;
}
