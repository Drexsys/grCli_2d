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

    if (position->x + size->width < 0 || position->y + size->height < 0) return;
    if (position->x > screen->getWidth() - 1 || position->y > screen->getHeight() - 1) return;

    short startPosY = 0, startPosX = 0;

    if (position->x < 0)
        startPosX = short(-position->x);
    if (position->y < 0)
        startPosY = short(-position->y);

    for (short y = startPosY; y < size->height; y++) {
        for (short x = startPosX; x < size->width; x++) {
            if (position->x + x > screen->getWidth() - 1)
                break;
            scr[y + position->y][x + position->x] = sprite[y][x];
        }
        if (position->y + y > screen->getHeight() - 1)
            break;
    }
}

bool Object::isCrossing(Object *object) const {
    if (this->position->x <= object->position->x && this->position->x + this->size->width >= object->position->x)
        if (this->position->y <= object->position->y && this->position->y + this->size->height >= object->position->y)
            return true;

    if (object->position->x <= this->position->x && object->position->x + object->size->width >= this->position->x)
        if (object->position->y <= this->position->y && object->position->y + object->size->height >= this->position->y)
            return true;

    return false;
}

Point* Object::getPosition() const {
    return this->position;
}

Size* Object::getSize() const {
    return this->size;
}
