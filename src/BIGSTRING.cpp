#include"BIGSTRING.h"

BIGSTRING::BIGSTRING(short x, short y, const std::string &text, Font *font)
    : Object(x, y), text(text), font(font) {

    word = new BigChar*[this->text.length()];

    short lX = this->position->x;
    for (int i = 0; i < this->text.length(); i++) {
        word[i] = new BigChar(lX, this->position->y, text[i], this->font);
        
        lX += word[i]->getSize()->width + 1;
    }

}

void BIGSTRING::show(Screen* screen) const {

    for (short i = 0; i < this->text.length(); i++) {
        word[i]->show(screen);   
    }

}
