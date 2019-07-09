//Atomic Tetris
//Header file for NCurses frontend
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#include "front_ncurses.h"

void front_ncurses::start() {
  //Initialize ncurses
  initscr();
  raw();
  keypad(stdscr, TRUE);

  //Initialize color
  start_color();
}

void front_ncurses::quit() {
  endwin();
}
