//
// Created by drexsys on 03.05.26.
//

#include "Score.h"

Score::Score(short x, short y) : SString(x, y, "0") {}

unsigned int Score::getScore() const {
    return score;
}

void Score::increaseScore() {
    if (timer != 0) {
        timer--;
        return;
    }
    score++;
    timer = 15;
    this->setText(std::to_string(score));
}
