#include "front_ncurses.h"
#include "GameBoard.h"

int main() {
  GameBoard gb_test;
  front_ncurses fn;

  //TODO: remove - test randomizing the board
  for (int y = 0; y < 20; y++) {
    gb_test.randomize_line(y);
  }

  fn.start();
  fn.render_board(gb_test);
  fn.wait_for_input();
  fn.quit();
}
