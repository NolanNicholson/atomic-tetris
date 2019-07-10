//Atomic Tetris
//Header file for Piece class
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#ifndef PIECE_H
#define PIECE_H

#include "Block.h"

class Piece {
  public:
    void rotate(bool clockwise = false);
    //Rotates the piece in place.

    void get_coords(int x[], int y[]) const;
    //Copies the piece's local coordinates to x and y.

    BlockType get_type() const;
    //Returns the type of the piece.

    Piece(BlockType type = kNoBlock);
    //Constructor. Initializes the Piece to the BlockType `type`.
    //If `type` is kNoBlock (the default), then the piece type
    //is randomized.

    static const int max_num_blocks = 4;

  private:
    Block blocks[max_num_blocks];
    int local_x[max_num_blocks];
    int local_y[max_num_blocks];
    BlockType piece_type;
};

#endif //PIECE_H
