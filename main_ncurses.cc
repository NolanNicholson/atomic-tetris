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
  for (int i = 0; i < 6; i++) {
    fn.render_board(gb_test);
    gb_test.move_active_piece(1, 1);
    fn.wait_for_input();
  }
  fn.quit();
}
