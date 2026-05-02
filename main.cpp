#include "src/Screen.h"
#include "src/Object.h"
#include "src/SString.h"
#include "src/Button.h"

#include<ncurses.h>

void initNcurses() {
    // Ініціалізація ncurses
    initscr();
    cbreak();           // Вимкнути буферизацію
    noecho();           // Не показувати натиснуті клавіші
    keypad(stdscr, TRUE); // Включити спеціальні клавіші
    nodelay(stdscr, TRUE); // Неблокуючий ввід
}

int main() {
    initNcurses();

    auto screen = new Screen(80, 24, 2313682943);

    char **objectSpr = new char*[1];
    objectSpr[0] = new char[5]{'H', 'e', 'l', 'l', 'o'};
    const auto object = new Object(0, 0, objectSpr, 5, 1);

    const auto sstring = new SString(0, 2, "World!");

    auto button = new Button(0, 4, "Button");
    auto button1 = new Button(0, 5, "Button");

    screen->makeEmpty();

    object->show(screen);
    sstring->show(screen);

    button->show(screen);

    button1->choose(true);
    button1->show(screen);

    screen->print();

    delete screen;

    //std::cout << "\033[2J\033[1;1H";
    endwin();

    return 0;
}