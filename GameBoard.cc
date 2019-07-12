//Atomic Tetris
//Implementation file for GameBoard class
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#include "GameBoard.h"

int GameBoard::get_score() const {
  return score;
}

int GameBoard::get_level() const {
  return level;
}

int GameBoard::get_lines() const {
  return lines;
}

bool GameBoard::get_game_over() const {
  return game_over;
}

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

bool GameBoard::is_valid_and_free_location(int y, int x) const {
  //Check if out-of-bounds
  if (!(y >= 0 && y < num_total_rows && x >= 0 && x < num_cols)) {
    return false;
  }
  //Check if occupied
  if (!board_contents[y][x].is_free()) {
    return false;
  }
  return true;
}

void GameBoard::reset_active_piece_coords() {
  active_piece_x = num_cols / 2;
  active_piece_y = num_visible_rows + 0;
}

bool GameBoard::move_active_piece(int dy, int dx) {
  //Moves the active piece dy units down and dx units right.
  int new_y = active_piece_y - dy;
  int new_x = active_piece_x + dx;

  int x_coords[Piece::max_num_blocks];
  int y_coords[Piece::max_num_blocks];
  active_piece.get_coords(x_coords, y_coords);

  //Check the new block coordinates for validity.
  //If the move was a downward move, then commit the piece.
  for (int i = 0; i < Piece::max_num_blocks; i++) {
    if (!is_valid_and_free_location(new_y + y_coords[i], new_x + x_coords[i])) {
      if (dy > 0)
        commit_active_piece();
      return false;
    }
  }

  //Apply the transformation if successful
  active_piece_y = new_y;
  active_piece_x = new_x;
  return true;
}

void GameBoard::snap_active_piece_down() {
  while (move_active_piece(1, 0)) {
    score++;
  }
}

bool GameBoard::rotate_active_piece(bool clockwise) {
  int new_x[Piece::max_num_blocks];
  int new_y[Piece::max_num_blocks];
  active_piece.get_rotated_coords(clockwise, new_x, new_y);

  for (int i = 0; i < Piece::max_num_blocks; i++) {
    if (!is_valid_and_free_location(
          active_piece_y + new_y[i],
          active_piece_x + new_x[i]))
      return false;
  }

  active_piece.rotate(clockwise);
  return true;
}

void GameBoard::commit_active_piece() {
  //Get coordinate and type information for the active piece
  int x, y;
  int x_coords[Piece::max_num_blocks];
  int y_coords[Piece::max_num_blocks];
  active_piece.get_coords(x_coords, y_coords);
  BlockType active_type = active_piece.get_type();

  //Change the appropriate blocks on the board to the active piece's type
  for (int i = 0; i < Piece::max_num_blocks; i++) {
    x = x_coords[i] + active_piece_x;
    y = y_coords[i] + active_piece_y;
    if (y >= 0 && y < num_total_rows && x >= 0 && x < num_cols)
      board_contents[y][x].type = active_type;
  }

  //Check for completed lines to clear
  for (int i = 0; i < num_total_rows; i++) {
    if (check_line_full(i)) {
      lines_currently_clearing[i] = true;
    }
  }

  //Reset the active piece coordinates (to the top of the screen)
  reset_active_piece_coords();
  //Set the active piece to the (former) next piece
  active_piece = next_piece;
  //Generate a new next piece
  Piece new_piece;
  next_piece = new_piece;

  //Check if the game is over
  for (int y = num_visible_rows + 1; y < num_total_rows; y++) {
    for (int x = 0; x < num_cols; x++) {
      if (!board_contents[y][x].is_free()) {
        game_over = true;
      }
    }
  }
}

void GameBoard::finish_clearing_lines() {
  int cleared_lines = 0;
  for (int y = num_visible_rows - 1; y >= 0; y--) {
    if (lines_currently_clearing[y]) {
      //remove the blocks
      remove_line(y);
      //need to increment lines one a time, but need to count total
      //lines cleared for scoring reasons
      cleared_lines++;
      lines++;
      if (!(lines % 10))
        level++;
      //okay we don't need to clear it anymore
      lines_currently_clearing[y] = false;
    }
  }

  //Score based on the number of lines cleared
  switch(cleared_lines) {
    case 1: score += 40 * level;    break;
    case 2: score += 100 * level;   break;
    case 3: score += 300 * level;   break;
    case 4: score += 1200 * level;  break;
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
  reset_active_piece_coords();
}
