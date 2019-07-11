#include "front_ncurses.h"
#include "GameBoard.h"

int main() {
  GameBoard gb_test;
  front_ncurses fn;

  bool user_quit = false;
  fn.start();
  while (true) {
    fn.render_board(gb_test);
    fn.handle_input(gb_test, user_quit);
    if (user_quit)
      break;
  }

  fn.quit();
  return 0;
}
