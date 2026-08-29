//
// Created by drexsys on 24.04.26.
//

#ifndef GRCLI_2D_SCREEN_H
#define GRCLI_2D_SCREEN_H

#include "structers.h"

class Screen {
protected:
    Size *size;
    char **plane;
    char **emptyPlane;
    char defChar;

    const unsigned int FPS;

public:
    Screen(short width, short height, unsigned int FPS, char defChar = ' ');
    ~Screen();

    void makeEmpty();
    void print() const;

    [[nodiscard]] char** getPlane() const;

    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;

    void setDefChar(char ch);

protected:
    Screen(short width, short height, char defChar);

private:
    void initPlane();

};

#endif //GRCLI_2D_SCREEN_H
