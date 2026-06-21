#ifndef GRCLI_2d_BIGCHAR_H
#define GRCLI_2d_BIGCHAR_H

#include"Object.h"
#include"Font.h"

class BigChar: public Object {

public:
    BigChar(short x, short y, char ch, Font* font);

};

#endif //GRCLI_2d_BIGCHAR_H
