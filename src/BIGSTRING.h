#ifndef GRCLI_2D_BIGSTRING_H
#define GRCLI_2D_BIGSTRING_H

#include"Font.h"
#include"BigChar.h"
#include"Object.h"

class BIGSTRING: public Object {

    Font* font;
    BigChar** word;
    const std::string &text;

public:
    BIGSTRING(short x, short y, const std::string &text, Font* font);

    void show(Screen *screen) const override;


};


#endif //GRCLI_2D_BIGSTRING_H
