//Atomic Tetris
//Header file for NCurses frontend
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#ifndef FRONT_NCURSES_H
#define FRONT_NCURSES_H

#include "GameBoard.h"
#include <ncurses.h>

class front_ncurses {
  public:
    void start();
    //Initializes ncurses graphical frontend and starts the game

    void render_block(int y, int x, BlockType bt);
    //Renders a single block of a specified BlockType to the screen

    void render_board(GameBoard gb);
    //Renders the screen, including the provided GameBoard

    void wait_for_input();
    //Just waits for input - allows pausing and examining output

    void quit();
    //Wraps up ncurses graphical frontend and quits the game

  private:
    WINDOW *gameboard_win;

};

#endif //FRONT_NCURSES_H
