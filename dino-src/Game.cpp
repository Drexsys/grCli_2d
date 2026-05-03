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
                return score->getScore();
            case 'j':
                dino->setJumping();
                break;

            default: ;
        }

        score->increaseScore();
        enemy->move();
        dino->jump();

        draw();
    }
}

void Game::draw() const {
    screen->makeEmpty();

    enemy->show(screen);
    dino->show(screen);

    score->show(screen);

    screen->print();
}

char Game::chooseAction() const {
    switch (keyPressed) {
        case 'q':
            return 'e';
        case ' ':
            return 'j';

        default:
            return ' ';
    }
}
