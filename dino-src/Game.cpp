//
// Created by drexsys on 02.05.26.
//

#include "Game.h"

#include <ncurses.h>

Game::Game(Screen* screen): screen(screen) {
    dino = new Dino(10, 17);
    enemy = new Enemy(50, 17);
    score = new Score(1, 1);
}

Game::~Game() {
    delete dino;
    delete enemy;
    delete score;
}

unsigned int Game::run() {
    while (true) {
        keyPressed = getch();

        switch (chooseAction()) {
            case 'e':
                return 0;
            default: ;
        }

        score->increaseScore();
        draw();
    }
}

void Game::draw() const {
    screen->makeEmpty();

    dino->show(screen);
    enemy->show(screen);

    score->show(screen);

    screen->print();
}

char Game::chooseAction() {
    switch (keyPressed) {
        case 'q':
            return 'e';
        default:
            return ' ';
    }
}
