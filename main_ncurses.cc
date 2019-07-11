#include "front_ncurses.h"
#include "GameBoard.h"

int main() {
  GameBoard gb_test;
  front_ncurses fn;

  bool user_quit = false;
  fn.start();
  for (int i = 0; i < 20 * 20; i++) {
    fn.render_board(gb_test);
    fn.handle_input(gb_test, user_quit);
    if (user_quit) {
      break;
    }
    if (i && !(i % 20))
      gb_test.commit_active_piece();
  }

  fn.quit();
  return 0;
}
