//Atomic Tetris
//Header file for NCurses frontend
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#ifndef FRONT_NCURSES_H
#define FRONT_NCURSES_H

#include "GameBoard.h"
#include <ncurses.h>

namespace front_ncurses {
  void start();
  //Initializes ncurses graphical frontend and starts the game

  void quit();
  //Wraps up ncurses graphical frontend and quits the game
};

#endif //FRONT_NCURSES_H
