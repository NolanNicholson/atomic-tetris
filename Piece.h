//Atomic Tetris
//Header file for Piece class
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#ifndef PIECE_H
#define PIECE_H

#include "Block.h"

class Piece {
  private:
    void rotate(bool clockwise = false);

  private:
    Block blocks[4];
};

#endif //PIECE_H
