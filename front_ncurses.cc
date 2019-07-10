//Atomic Tetris
//Implementation file for NCurses frontend
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
  use_default_colors();
}

void front_ncurses::render(GameBoard gb) {
  for (int y = 0; y < 20; y++) {
    for (int x = 0; x < 10; x++) {
      //Since characters are half-width, we have to render twice
      //to make a square
      move(y, 2*x);
      addch('[');
      move(y, 2*x+1);
      addch(']');
    }
  }
}

void front_ncurses::wait_for_input() {
  getch();
}

void front_ncurses::quit() {
  endwin();
}
