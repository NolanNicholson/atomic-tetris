//Atomic Tetris
//Implementation file for Piece class
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#include "Piece.h"

void Piece::rotate(bool clockwise) {

}

void Piece::get_coords(int x[], int y[]) const {
  for (int i = 0; i < max_num_blocks; i++) {
    x[i] = local_x[i];
    y[i] = local_y[i];
  }
}

BlockType Piece::get_type() const {
  return piece_type;
}

Piece::Piece(BlockType type) {
  if (type == kNoBlock) {
    //Randomize the piece type if it is kNoBlock
    type = kLBlock; //TODO
  }
  piece_type = type;

  //Designate the piece
  switch(type) {
    case kLBlock: local_x[0] = 0;
                  local_x[1] = 0;
                  local_x[2] = 0;
                  local_x[3] = 1;
                  local_y[0] = 1;
                  local_y[1] = 0;
                  local_y[2] = -1;
                  local_y[3] = -1;
                  break;
  }
}
