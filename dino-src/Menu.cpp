//
// Created by drexsys on 02.05.26.
//

#include "Menu.h"

#include<ncurses.h>

Menu::Menu(Screen *screen): screen(screen) {
    start = new Button(1, 4, "Start");
    start->choose(true);
    exit = new Button(1, 6, "Exit");

    lastResL = new SString(1, 8, "Last result: 0");
    bestResL = new SString(1, 10, "Best result: 0");
}

Menu::~Menu() {
    delete start;
    delete exit;
    delete lastResL;
    delete bestResL;
}

bool Menu::run() {
    while (true) {
        keyPressed = getch();

        switch (chooseAction()) {
            case 's':
                return true;
            case 'q':
                return false;
            default: ;
        }

        draw();
    }
}

void Menu::draw() const {
    screen->makeEmpty();

    start->show(screen);
    exit->show(screen);

    lastResL->show(screen);
    bestResL->show(screen);

    screen->print();
}

char Menu::chooseAction() {
    switch (keyPressed) {
        case KEY_UP:
            if (exit->getChoose()) {
                exit->choose(false);
                start->choose(true);
            } else {
                exit->choose(true);
                start->choose(false);
            } break;
        case KEY_DOWN:
            if (start->getChoose()) {
                exit->choose(true);
                start->choose(false);
            } else {
                exit->choose(false);
                start->choose(true);
            } break;
        case 'q':
            if (start->getChoose()) return 's';
            return 'q';

        default: ;
    }
    return ' ';
}

bool Menu::getIsMenu() const {
    return isMenu;
}

void Menu::setIsMenu(bool value) {
    isMenu = value;
}
