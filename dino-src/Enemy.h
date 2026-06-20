//
// Created by drexsys on 03.05.26.
//

#ifndef GRCLI_2D_ENEMY_H
#define GRCLI_2D_ENEMY_H

#include "../src/Object.h"

class Enemy: public Object {
    unsigned short timer = 15;

public:
    Enemy(short x, short y);

    void move();
};


#endif //GRCLI_2D_ENEMY_H
