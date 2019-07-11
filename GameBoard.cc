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

Piece GameBoard::get_next_piece() const {
  return next_piece;
}

Piece GameBoard::get_active_piece() const {
  return active_piece;
}

void GameBoard::get_active_piece_yx(int& y, int& x) const {
  y = active_piece_y;
  x = active_piece_x;
}

void GameBoard::move_active_piece(int dy, int dx) {
  //Moves the active piece dy units down and dx units right.
  active_piece_y -= dy;
  active_piece_x += dx;
}

void GameBoard::commit_active_piece() {
  int x, y;
  int x_coords[Piece::max_num_blocks];
  int y_coords[Piece::max_num_blocks];
  active_piece.get_coords(x_coords, y_coords);
  BlockType active_type = active_piece.get_type();

  for (int i = 0; i < Piece::max_num_blocks; i++) {
    x = x_coords[i] + active_piece_x;
    y = y_coords[i] + active_piece_y;
    if (y >= 0 && y < num_total_rows && x >= 0 && x < num_cols)
      board_contents[y][x].type = active_type;
  }
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
