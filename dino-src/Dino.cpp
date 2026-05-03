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

void Dino::setJumping() {
    if (!isFalling)
        isJumping = true;
}

void Dino::jump() {
    if (!isJumping && !isFalling) return;
    if (isFalling) return fall();

    if (timer != 0) {
        timer--;
        return;
    }
    timer = 3;
    position->y--;
    if (position->y == maxJump) {
        isJumping = false;
        isFalling = true;
    }
}

void Dino::fall() {
    if (flyingTimer != 0) {
        flyingTimer--;
        return;
    }
    if (timer != 0) {
        timer --;
        return;
    }
    timer = 3;
    position->y++;
    if (position->y == 17) {
        isFalling = false;
        flyingTimer = 5;
    }
}
