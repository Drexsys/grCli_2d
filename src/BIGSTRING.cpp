#include"BIGSTRING.h"
#include<iostream>

BIGSTRING::BIGSTRING(short x, short y, const std::string &text, Font *font)
    : Object(x, y), font(font), wordLength(text.length()) {

    word = new BigChar*[this->wordLength];

    short lX = this->position->x;
    for (int i = 0; i < this->wordLength; i++) {
        word[i] = new BigChar(lX, this->position->y, text[i], this->font);
        
        lX += word[i]->getSize()->width + 1;
    }

}

void BIGSTRING::show(Screen* screen) const {

    for (short i = 0; i < this->wordLength; i++) {
        word[i]->show(screen);   
    }

}
