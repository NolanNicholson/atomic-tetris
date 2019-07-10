//Atomic Tetris
//Implementation file for NCurses frontend
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#include "front_ncurses.h"

void front_ncurses::start() {
  //Initialize ncurses
  initscr();
  cbreak();
  keypad(stdscr, TRUE);

  //Initialize color
  start_color();
  use_default_colors();

  //Create window to hold the game board
  gameboard_win = newwin(
      GameBoard::num_total_rows,
      GameBoard::num_cols,
      2, 2); //starty, startx
  box(gameboard_win, 0, 0);

}

void front_ncurses::render(GameBoard gb) {
  for (int y = 0; y < 20; y++) {
    for (int x = 0; x < 10; x++) {
      //Since characters are half-width, we have to render twice
      //to make a square
      //mvwaddch(gameboard_win, y, 2*x  , '[');
      //mvwaddch(gameboard_win, y, 2*x+1, ']');

      mvaddch(y, 2*x  , '[');
      mvaddch(y, 2*x+1, ']');
    }
  }
  wrefresh(gameboard_win);
}

void front_ncurses::wait_for_input() {
  getch();
}

void front_ncurses::quit() {
  delwin(gameboard_win);
  endwin();
}
