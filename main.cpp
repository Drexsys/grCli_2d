#include "src/Screen.h"
#include "src/Object.h"

int main() {
    auto screen = new Screen(80, 24);

    char **objectSpr = new char*[1];
    objectSpr[0] = new char[5]{'H', 'e', 'l', 'l', 'o'};
    const auto object = new Object(0, 0, objectSpr, 5, 1);

    screen->makeEmpty();

    object->show(screen);

    screen->print();

    delete screen;

    return 0;
}