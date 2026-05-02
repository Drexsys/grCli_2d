//
// Created by drexsys on 02.05.26.
//

#ifndef GRCLI_2D_BUTTON_H
#define GRCLI_2D_BUTTON_H

#include "SString.h"

class Button: public SString {

    bool isChosen = false;
    char **defSprite;

public:
    Button(short x, short y, const std::string &text);

    void choose(bool isChoose);
    bool getChoose() const;
};


#endif //GRCLI_2D_BUTTON_H
