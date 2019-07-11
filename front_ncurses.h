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

    void render_block(WINDOW *w, int y, int x, BlockType bt);
    //Renders a single block of a specified BlockType to the screen.
    //Renders in the ncurses WINDOW pointed to by w, at in-window
    //coordinates y and x

    void render_piece(WINDOW *w, Piece p, int y, int x);
    //Renders a game piece.
    //Renders in the ncurses WINDOW pointed to by w, at in-window
    //coordinates y and x

    void render_board(GameBoard gb);
    //Renders the screen, including the provided GameBoard

    void handle_input(GameBoard& gb);
    //Handles input, making changes to `gb`'s state to move pieces, etc.
    
    void wait_for_input();
    //Just waits for input - allows pausing and examining output

    void quit();
    //Wraps up ncurses graphical frontend and quits the game

  private:
    WINDOW *gameboard_win;
    WINDOW *gameboard_border_win;

};

#endif //FRONT_NCURSES_H
