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
      GameBoard::num_visible_rows,
      GameBoard::num_cols * 2, // *2 because chars are half-width
      2, 4); //starty, startx
  refresh();

  //Make cursor invisible
  curs_set(0);

}

void front_ncurses::render_block(int y, int x, BlockType bt) {
  //Since characters are half-width, we have to render twice
  //to make a square
  if (bt != kNoBlock) {
    mvwaddch(gameboard_win, GameBoard::num_visible_rows-1-y, 2*x  , '[');
    mvwaddch(gameboard_win, GameBoard::num_visible_rows-1-y, 2*x+1, ']');
  }
}

void front_ncurses::render_board(GameBoard gb) {

  for (int y = 0; y < gb.num_visible_rows; y++) {
    for (int x = 0; x < gb.num_cols; x++) {
      BlockType bt = gb.get_block_type_at(y, x);
      front_ncurses::render_block(y, x, bt);
    }
  }
  wrefresh(gameboard_win);
  
  mvprintw(3, 30, "Score:");
  mvprintw(6, 30, "Level:");
  mvprintw(9, 30, "Lines:");
  refresh();
}

void front_ncurses::wait_for_input() {
  getch();
}

void front_ncurses::quit() {
  delwin(gameboard_win);
  endwin();
}
