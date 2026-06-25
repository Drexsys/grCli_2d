#ifndef GRCLI_2D_SECSCREEN_H
#define GRCLI_2D_SECSCREEN_H

#include "Object.h"
#include "Screen.h"

class SecScreen: public Screen, public Object {

public:
    SecScreen(short x, short y, short width, short height, char defChar = ' ');
    ~SecScreen();

};

#endif //GRCLI_2D_SECSCREEN_H

