//
// Created by drexsys on 25.04.26.
//

#ifndef GRCLI_2D_OBJECT_H
#define GRCLI_2D_OBJECT_H

#include "structers.h"
#include "Screen.h"

class Object {
    Point *position;
    char **sprite;
    Size *size;

public:
    Object(short x, short y, char **sprite, short width, short height);
    ~Object();

    void show(Screen *screen) const;
};

#endif //GRCLI_2D_OBJECT_H
