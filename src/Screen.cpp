//
// Created by drexsys on 24.04.26.
//

#include "Screen.h"
#include <iostream>

Screen::Screen(short width, short height) {
    size = new Size{width, height};
    plane = nullptr;
}

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

void Screen::makeEmpty() {
    if (size == nullptr)
        return;

    bool isInitPlane = true;

    if (plane == nullptr) {
        isInitPlane = false;
        plane = new char*[size->height];
    }

    for (short y = 0; y < size->height; y++) {
        if (!isInitPlane) {
            plane[y] = new char[size->width + 1];
            plane[y][size->width] = '\0';
        }

        for (short x = 0; x < size->width; x++) {
            plane[y][x] = ' ';
        }
    }
}

void Screen::print() const {
    if (plane == nullptr || size == nullptr)
        return;

    for (short y = 0; y < size->height; y++)
        std::cout << plane[y] << std::endl;
}

char** Screen::getPlane() const {
    return plane;
}

