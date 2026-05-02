//
// Created by drexsys on 02.05.26.
//

#include "Button.h"

Button::Button(short x, short y, const std::string &text)
    : SString(x, y, text) {

    defSprite = new char*[1];
    defSprite[0] = new char[size->width + 1];
    defSprite[0][0] = '>';
    for (short i = 1; i < size->width + 2; i++)
        defSprite[0][i] = sprite[0][i - 1];
}

void Button::choose(const bool isChoose) {
    if (isChosen && isChoose) return;
    if (!isChosen && !isChoose) return;

    isChosen = !isChosen;

    if (isChoose) size->width += 1;
    else size->width -= 1;

    char** temp = sprite;
    sprite = defSprite;
    defSprite = temp;
}

bool Button::getChoose() const {
    return isChosen;
}
