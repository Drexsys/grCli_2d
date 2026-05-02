#include "src/Screen.h"
#include "src/Object.h"
#include "src/SString.h"

//#include <iostream>

int main() {
    auto screen = new Screen(80, 24);

    char **objectSpr = new char*[1];
    objectSpr[0] = new char[5]{'H', 'e', 'l', 'l', 'o'};
    const auto object = new Object(0, 0, objectSpr, 5, 1);

    const auto sstring = new SString(0, 2, "World!");

    screen->makeEmpty();

    object->show(screen);
    sstring->show(screen);

    screen->print();

    delete screen;

    //std::cout << "\033[2J\033[1;1H";

    return 0;
}