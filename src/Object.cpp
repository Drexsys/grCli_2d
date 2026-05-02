//
// Created by drexsys on 25.04.26.
//

#include "Object.h"

Object::Object(short x, short y, char **sprite, short width, short height) {
    position = new Point{x, y};
    this->sprite = sprite;
    size = new Size{width, height};
}

Object::Object(short x, short y) {
    position = new Point{x, y};
    sprite = nullptr;
    size = nullptr;
}

Object::~Object() {
    if (sprite != nullptr && size != nullptr) {
        for (short i = 0; i < size->height; i++)
            delete[] sprite[i];

        delete[] sprite;
        sprite = nullptr;

        delete size;
        size = nullptr;
    }

    if (position != nullptr) {
        delete position;
        position = nullptr;
    }
}

void Object::show(Screen *screen) const {
    char** scr = screen->getPlane();

    for (short y = 0; y < size->height; y++) {
        for (short x = 0; x < size->width; x++) {
            scr[y + position->y][x + position->x] = sprite[y][x];
        }
    }
}
