//
// Created by drexsys on 02.05.26.
//

#include "Dino.h"

Dino::Dino(short x, short y) : Object(x, y) {
    size = new Size{4, 5};

    sprite = new char*[size->height];
    for (short i = 0; i < size->height; i++)
        sprite[i] = new char[]{'@', '@', '@', '@'};
}
