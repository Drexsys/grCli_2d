#include"Font.h"
#include<iostream>
#include<fstream>

Font::Font(const std::string &path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Font ERROR: file not found" << std::endl;
        return;
    }

    std::string tmp;
    while (true) {
        file >> tmp;
        if (tmp == "exit")
            break;

        char ch = tmp[0];
        LetterInf *tmpInf = new LetterInf;

        file >> tmpInf->width;
        file >> tmpInf->height;

        tmpInf->sprite = new char*[tmpInf->height];

        file.ignore();
        for (short i = 0; i < tmpInf->height; i++) {
            tmpInf->sprite[i] = new char[tmpInf->width + 1];

            file.getline(tmpInf->sprite[i], tmpInf->width + 1);
        }

        this->letters[ch] = tmpInf;
    }

}

Font::~Font() {

    for (auto &pair: letters) {
        delete pair.second;
    }

}

LetterInf* Font::findLetter(char ch) { 
    return this->letters[ch];
}
