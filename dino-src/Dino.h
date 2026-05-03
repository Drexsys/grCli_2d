//
// Created by drexsys on 02.05.26.
//

#ifndef GRCLI_2D_DINO_H
#define GRCLI_2D_DINO_H

#include "../src/Object.h"

class Dino: public Object {
    bool isJumping = false;
    bool isFalling = false;
    unsigned short timer = 3;
    unsigned short flyingTimer = 5;

    const unsigned short maxJump = 10;

public:
    Dino(short x, short y);

    void jump();
    void fall();
    void setJumping();
};


#endif //GRCLI_2D_DINO_H
