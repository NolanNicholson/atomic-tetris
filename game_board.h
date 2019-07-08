#ifndef GAMEBOARD_H
#define GAMEBOARD_H

//Atomic Tetris
//Header file for GameBoard class
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

class GameBoard {
  public:
    bool check_line(int y) const;
    //Checks whether the line at position y is full of blocks.

    void remove_line(int y);
    //Removes the line at position y.

  private:
    const int num_rows = 10;
    const int num_cols = 10;
}

#endif //GAMEBOARD_H
