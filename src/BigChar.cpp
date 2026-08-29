#include"BigChar.h"
#include"structers.h"

BigChar::BigChar(short x, short y, char ch, Font* font) 
    : Object(x, y) {


    LetterInf* charInf = font->findLetter(ch);

    this->size = new Size{charInf->width, charInf->height};
    this->sprite = charInf->sprite; 

}
