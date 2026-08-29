//
// Created by drexsys on 24.04.26.
//

#include "Screen.h"

#include <cstring>
#include <unistd.h>
#include <ncurses.h>

Screen::~Screen() {
    if (plane != nullptr && size != nullptr) {
        for (short y = 0; y < size->height; y++)
            delete[] plane[y];

        delete[] plane;
        plane = nullptr;
    }

    if (size != nullptr) {
        delete size;
        size = nullptr;
    }
}

Screen::Screen(short width, short height, const unsigned int FPS, char defChar)
    : FPS(FPS), defChar(defChar) {

    this->size = new Size{ width, height };

    this->initPlane();
}

void Screen::initPlane() {

    this->emptyPlane = new char*[this->size->height];
    this->plane = new char*[this->size->height];

    for (short y = 0; y < this->size->height; y++) {
        this->emptyPlane[y] = new char[this->size->width + 1];
        this->plane[y] = new char[this->size->width + 1];

        this->emptyPlane[y][this->size->width] = '\0';
        this->plane[y][this->size->width] = '\0';

        for (short x = 0; x < this->size->width; x++) {
            this->emptyPlane[y][x] = this->defChar;
            this->plane[y][x] = this->defChar;
        }
    }

}

Screen::Screen(short width, short height, char defChar) 
    : defChar(defChar), FPS(1) {
    this->size = new Size{ width, height };

    this->initPlane();
}

void Screen::makeEmpty() {
    for (int y = 0; y < size->height; ++y) {
        std::memcpy(plane[y], emptyPlane[y], size->width * sizeof(char));
    }
}

void Screen::print() const {
    if (plane == nullptr || size == nullptr)
        return;

    erase();
    for (short y = 0; y < size->height; y++)
        mvaddstr(y, 0, plane[y]);
    refresh();

    usleep(FPS);
}

char** Screen::getPlane() const {
    return plane;
}

int Screen::getHeight() const {
    return size->height;
}

int Screen::getWidth() const {
    return size->width;
}

void Screen::setDefChar(char ch) {
    this->defChar = ch;
}
