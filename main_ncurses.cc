#include "front_ncurses.h"
#include "GameBoard.h"

int main() {
  GameBoard gb_test;
  front_ncurses fn;

  fn.start();
  fn.render(gb_test);
  fn.wait_for_input();
  fn.quit();
}
