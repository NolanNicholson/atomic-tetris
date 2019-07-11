#include "front_ncurses.h"
#include "GameBoard.h"

int main() {
  GameBoard gb_test;
  front_ncurses fn;

  //Test randomizing the board. TODO: remove later
  for (int y = 0; y < 5; y++) {
    gb_test.randomize_line(y);
  }

  fn.start();
  for (int i = 0; i < 20; i++) {
    fn.render_board(gb_test);
    fn.handle_input(gb_test);
  }
  fn.quit();
}
