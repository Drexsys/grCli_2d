//
// Created by drexsys on 25.04.26.
//

#ifndef GRCLI_2D_STRUCTERS_H
#define GRCLI_2D_STRUCTERS_H

struct Point {
    short x;
    short y;
};

struct Size {
    short width;
    short height;
};

struct LetterInf: public Size {
    char** sprite;
};

#endif //GRCLI_2D_STRUCTERS_H
