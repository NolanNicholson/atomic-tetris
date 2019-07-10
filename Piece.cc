//Atomic Tetris
//Implementation file for Piece class
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#include "Piece.h"

void Piece::rotate(bool clockwise) {

}

Piece::Piece(BlockType type) {
  if (type == kNoBlock) {
    //Randomize the piece type if it is kNoBlock
    type == kLBlock; //TODO
  }

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
