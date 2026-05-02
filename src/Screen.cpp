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

Screen::Screen(short width, short height, const unsigned int FPS): FPS(FPS) {
    size = new Size{width, height};
    plane = nullptr;

    emptyPlane = new char*[size->height];
    plane = new char*[size->height];
    for (short y = 0; y < size->height; y++) {
        emptyPlane[y] = new char[size->width + 1];
        plane[y] = new char[size->width + 1];

        emptyPlane[y][size->width] = '\0';
        plane[y][size->width] = '\0';

        for (short x = 0; x < size->width; x++) {
            emptyPlane[y][x] = ' ';
            plane[y][x] = ' ';
        }
    }
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
