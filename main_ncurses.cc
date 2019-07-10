#include "front_ncurses.h"
#include "GameBoard.h"

int main() {
  GameBoard gb_test;
  front_ncurses fn;

  //Test randomizing the board. TODO: remove later
  for (int y = 0; y < 10; y++) {
    gb_test.randomize_line(y);
  }

  fn.start();
  fn.render_board(gb_test);
  fn.render_piece(stdscr, gb_test.get_next_piece(), 20, 30);
  fn.wait_for_input();
  fn.quit();
}
