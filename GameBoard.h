#ifndef GAMEBOARD_H
#define GAMEBOARD_H

//Atomic Tetris
//Header file for GameBoard class
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#include "Block.h"
#include "Piece.h"

class GameBoard {
  public:
    bool check_line_full(int y) const;
    //Checks whether the line at position y is full of blocks.

    BlockType get_block_type_at(int y, int x) const;
    //Returns the BlockType of the block at row y, column x.

    Piece get_next_piece() const;
    //Returns a copy of the next piece's Piece object

    Piece get_active_piece() const;
    //Returns a copy of the active piece's Piece object

    void get_active_piece_yx(int& y, int& x) const;
    //Assigns y and x to the coordinates of the active piece

    bool is_valid_and_free_location(int y, int x) const;
    //Returns true if the location at y, x is in-bounds and free, false if not

    bool move_active_piece(int dy, int dx);
    //Moves the active piece dy units down and dx units right,
    //but only if that move keeps the piece in a valid location.
    //Returns True if moved successfully, False if not.

    void reset_active_piece_coords();
    //Resets the coordinates of the active piece to the top of the board.

    void commit_active_piece();
    //Commits the active piece to the board.
    //Assigns next_piece to active_piece. Generates a new next_piece.

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

    //The active piece and its coordinates on the game board
    Piece active_piece;
    int active_piece_x;
    int active_piece_y;

    Piece next_piece;
};

#endif //GAMEBOARD_H
