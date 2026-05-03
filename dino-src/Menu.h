//
// Created by drexsys on 02.05.26.
//

#ifndef GRCLI_2D_MENU_H
#define GRCLI_2D_MENU_H

#include "../src/Screen.h"
#include "../src/Button.h"

class Menu {
    Screen *screen;

    Button *start;
    Button *exit;

    SString *lastResL;
    SString *bestResL;

    int keyPressed = 0;
    bool isMenu = true;

public:
    Menu(Screen *screen);
    ~Menu();

    bool run();

    [[nodiscard]] bool getIsMenu() const;
    void setIsMenu(bool value);

private:
    void draw() const;
    char chooseAction();
};


#endif //GRCLI_2D_MENU_H
