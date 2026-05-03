//
// Created by drexsys on 03.05.26.
//

#include "Enemy.h"

Enemy::Enemy(short x, short y) : Object(x, y) {
    size = new Size{5, 5};

    sprite = new char*[size->height];
    sprite[0] = new char[]{' ', ' ', 'O', ' ', 'O'};
    sprite[1] = new char[]{'O', ' ', 'O', 'O', 'O'};
    sprite[2] = new char[]{'O', 'O', 'O', ' ', ' '};
    sprite[3] = new char[]{' ', ' ', 'O', ' ', ' '};
    sprite[4] = new char[]{' ', ' ', 'O', ' ', ' '};
}
