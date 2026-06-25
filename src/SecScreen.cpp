#include "SecScreen.h"

SecScreen::SecScreen(short x, short y, short width, short height, char defChar) 
    : Screen(width, height, defChar), Object(x, y) {

    Object::sprite = Screen::plane;
    Object::size = Screen::size;   
}

SecScreen::~SecScreen() {

    Object::sprite = nullptr;
    Object::size = nullptr;

}
