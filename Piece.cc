//Atomic Tetris
//Implementation file for Piece class
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#include "Piece.h"

BlockType PieceRNG::get_random_type() {
  int type_num = distribution(generator); // generate random number

  return static_cast<BlockType>(type_num);
  //return static_cast<BlockType>(3);
}

PieceRNG::PieceRNG()
  : generator(rand_dev()), distribution(1, 7){
}

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
  PieceRNG p_rng;

  if (type == kNoBlock) {
    //Randomize the piece type if it is kNoBlock
    type = p_rng.get_random_type();
  }
  piece_type = type;

  int *x = &local_x[0], *y = &local_y[0]; //aliases for more compact code

  //Designate the piece
  switch(type) {
    case kRBlock: x[0] =  0; x[1] =  0; x[2] =  0; x[3] =  1;
                  y[0] =  1; y[1] =  0; y[2] = -1; y[3] = -1;
                  break;
    case kLBlock: x[0] =  0; x[1] =  0; x[2] =  0; x[3] = -1;
                  y[0] =  1; y[1] =  0; y[2] = -1; y[3] = -1;
                  break;
    case kSBlock: x[0] =  0; x[1] =  0; x[2] =  1; x[3] =  1;
                  y[0] = -1; y[1] =  0; y[2] =  0; y[3] =  1;
                  break;
    case kZBlock: x[0] =  0; x[1] =  0; x[2] =  1; x[3] =  1;
                  y[0] =  1; y[1] =  0; y[2] =  0; y[3] = -1;
                  break;
    case kIBlock: x[0] = -1; x[1] =  0; x[2] =  1; x[3] =  2;
                  y[0] =  0; y[1] =  0; y[2] =  0; y[3] =  0;
                  break;
    case kOBlock: x[0] =  0; x[1] =  0; x[2] =  1; x[3] =  1;
                  y[0] =  0; y[1] =  1; y[2] =  0; y[3] =  1;
                  break;
    case kTBlock: x[0] = -1; x[1] =  0; x[2] =  0; x[3] =  1;
                  y[0] =  0; y[1] =  0; y[2] =  1; y[3] =  0;
                  break;
  }
}
