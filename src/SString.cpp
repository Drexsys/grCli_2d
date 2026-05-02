//
// Created by drexsys on 02.05.26.
//

#include "SString.h"

SString::SString(short x, short y, const std::string &text)
    : Object(x, y) {

    const auto lenText = short(text.length());

    sprite = new char*[1];
    sprite[0] = new char[lenText];

    for (short i = 0; i < lenText; i++)
        sprite[0][i] = text[i];

    size = new Size{lenText, 1};
}
