#ifndef GRCLI_2D_FONT_H
#define GRCLI_2D_FONT_H

#include<string>
#include<map>
#include"structers.h"

class Font {

    std::map<char, LetterInf*> letters;

public:
    Font(const std::string &path);
    ~Font();

    LetterInf* findLetter(char ch);

};

#endif //GRCLI_2D_FONT_H
