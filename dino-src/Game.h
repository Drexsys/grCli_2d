//
// Created by drexsys on 02.05.26.
//

#ifndef GRCLI_2D_GAME_H
#define GRCLI_2D_GAME_H

#include "../src/Screen.h"
#include "Dino.h"
#include "Enemy.h"
#include "Score.h"

class Game {
    Screen* screen;

    Dino* dino;
    Enemy* enemy;
    Score* score;

    int keyPressed = 0;

public:
    Game(Screen* screen);
    ~Game();

    unsigned int run();

private:
    void draw() const;
    char chooseAction();
};


#endif //GRCLI_2D_GAME_H
