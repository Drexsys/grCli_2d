#include "src/Screen.h"
#include "src/Object.h"
#include "src/SString.h"
#include "src/Button.h"
#include "src/Font.h"
#include "src/BigChar.h"
#include "src/BIGSTRING.h"
#include "src/SecScreen.h"

#include <ncurses.h>

void initNcurses() {
    // Ініціалізація ncurses
    initscr();
    cbreak();           // Вимкнути буферизацію
    noecho();           // Не показувати натиснуті клавіші
    keypad(stdscr, TRUE); // Включити спеціальні клавіші
    nodelay(stdscr, TRUE); // Неблокуючий ввід
}

int main() {
    Font* testFont = new Font("../font.txt");

    initNcurses();

    //unsigned int fps = 99999999U;
    unsigned int fps = 9U;

    auto screen = new Screen(80, 24, fps);

    char **objectSpr = new char*[1];
    objectSpr[0] = new char[5]{'H', 'e', 'l', 'l', 'o'};
    const auto object = new Object(0, 0, objectSpr, 5, 1);

    const auto sstring = new SString(0, 2, "World!");

    auto button = new Button(0, 4, "Button");
    auto button1 = new Button(0, 5, "Button");

    auto secScreen = new SecScreen(10, 10, 5, 5, '.');

    screen->makeEmpty();

    object->show(secScreen);
    sstring->show(screen);

    button->show(screen);

    button1->choose(true);
    button1->show(screen);

    secScreen->show(screen);

    screen->print();

    delete screen;
    delete testFont;
    delete secScreen;

    endwin();

    return 0;
}
