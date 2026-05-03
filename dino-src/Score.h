//
// Created by drexsys on 03.05.26.
//

#ifndef GRCLI_2D_SCORE_H
#define GRCLI_2D_SCORE_H

#include "../src/SString.h"

class Score: public SString {

    unsigned int score = 0;
    unsigned short timer = 15;

public:
    Score(short x, short y);

    unsigned int getScore() const;
    void increaseScore();
};


#endif //GRCLI_2D_SCORE_H
