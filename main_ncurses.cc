#include "front_ncurses.h"
#include "GameBoard.h"

int main() {
  GameBoard gb_test;

  front_ncurses::start();
  front_ncurses::render(gb_test);
  front_ncurses::wait_for_input();
  front_ncurses::quit();
}
