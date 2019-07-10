//Atomic Tetris
//Implementation file for GameBoard class
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#include "GameBoard.h"

bool GameBoard::check_line_full(int y) const {
  for (int x = 0; x < num_cols; x++) {
    if (board_contents[y][x].is_free()) {
      return false;
    }
  }
  return true;
}

BlockType GameBoard::get_block_type_at(int y, int x) const {
  return board_contents[y][x].type;
}

void GameBoard::remove_line(int y_remove) {
  //Move down all of the existing pieces
  for (int y = y_remove; y < num_total_rows - 1; y++) {
    for (int x = 0; x < num_cols; x++) {
      board_contents[y][x] = board_contents[y+1][x];
    }
  }

  //Empty the top row
  for (int x = 0; x < num_cols; x++) {
    board_contents[num_total_rows - 1][x].free();
  }
}

void GameBoard::randomize_line(int y) {
  for (int x = 0; x < num_cols; x++) {
    //TODO: make random
    //board_contents[y][x].type = static_cast<BlockType>(x % 8);
    board_contents[y][x].type = static_cast<BlockType>((x+y) % 8);
  }
}

GameBoard::GameBoard() {
  //Free the entire board
  for (int y = 0; y < num_total_rows; y++) {
    for (int x = 0; x < num_cols; x++) {
      board_contents[y][x].free();
    }
  }
}
