//
// Created by drexsys on 24.04.26.
//

#ifndef GRCLI_2D_SCREEN_H
#define GRCLI_2D_SCREEN_H

#include "structers.h"

class Screen {
    Size *size;
    char **plane;

public:
    Screen(short width, short height);
    ~Screen();

    void makeEmpty();
    void print() const;

    [[nodiscard]] char** getPlane() const;
};


#endif //GRCLI_2D_SCREEN_H
