//Atomic Tetris
//Header file for Block class
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#ifndef BLOCK_H
#define BLOCK_H

enum BlockType {
  kNoBlock,
  kLBlock,
  kRBlock,
  kIBlock,
  kSBlock,
  kZBlock,
  kTBlock,
  kOBlock
};

class Block {
  public:
    BlockType type;

    bool is_free() const;
    //Returns True if the block is free, False otherwise

    void free();
    //Frees the block space
};

#endif //BLOCK_H
