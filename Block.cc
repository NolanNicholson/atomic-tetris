//Atomic Tetris
//Implementation file for Block class
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#include "Block.h"

bool Block::is_free() const {
  return type == kNoBlock;
}

void Block::free() {
  type = kNoBlock;
}
