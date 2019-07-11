#include "front_ncurses.h"
#include "GameBoard.h"

int main() {
  GameBoard gb_test;
  front_ncurses fn;

  fn.start();
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      fn.render_board(gb_test);
      fn.handle_input(gb_test);
    }
    gb_test.commit_active_piece();
  }
  fn.quit();
}
