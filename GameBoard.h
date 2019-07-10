#ifndef GAMEBOARD_H
#define GAMEBOARD_H

//Atomic Tetris
//Header file for GameBoard class
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#include "Block.h"

class GameBoard {
  public:
    bool check_line_full(int y) const;
    //Checks whether the line at position y is full of blocks.

    BlockType get_block_type_at(int y, int x) const;
    //Returns the BlockType of the block at row y, column x.

    void remove_line(int y_remove);
    //Removes the line at position y.

    void randomize_line(int y);
    //Randomizes all of the blocks in line y.

    GameBoard();

    static const int num_visible_rows = 20; 
    static const int num_buffer_rows = 4; //hold pieces above the player view
    static const int num_total_rows = num_buffer_rows + num_visible_rows;
    static const int num_cols = 10;

  private:

    //Internal representation of the game board.
    //y = 0 is at the bottom, not the top -
    //this makes the buffer rows at the top a little less confusing
    Block board_contents[num_total_rows][num_cols];
};

#endif //GAMEBOARD_H
