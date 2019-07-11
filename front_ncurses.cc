//Atomic Tetris
//Implementation file for NCurses frontend
//Tetris is (c) its current owners
//This particular implementation is (c) Nolan Nicholson, 2019,
//and is not intended for commercial sale

#include "front_ncurses.h"

void front_ncurses::start() {
  //Initialize ncurses
  initscr();
  cbreak();
  keypad(stdscr, TRUE);

  //Initialize color
  start_color();
  use_default_colors();

  //Initialize color pairs
  //1-7 are for blocks: back foreground, colored background
  for (int i = 1; i <= 7; i++) {
    init_pair(i, COLOR_BLACK, i);
  }

  //Create border for the game board
  gameboard_border_win = newwin(
      GameBoard::num_visible_rows + 2,
      GameBoard::num_cols * 2 + 2,
      0, 1);

  //Create window to hold the game board
  gameboard_win = newwin(
      GameBoard::num_visible_rows,
      GameBoard::num_cols * 2, // *2 because chars are half-width
      1, 2); //starty, startx

  //Create window to hold game info (including next piece)
  game_info_win = newwin(
      20,
      10,
      3, 26);

  refresh();

  //Make cursor invisible
  curs_set(0);

}

void front_ncurses::render_block(WINDOW *w, int y, int x, BlockType bt) {

  int cp = 0; //color pair number

  switch (bt) {
    case kLBlock: cp = 1; break;
    case kRBlock: cp = 2; break;
    case kSBlock: cp = 3; break;
    case kZBlock: cp = 4; break;
    case kIBlock: cp = 5; break;
    case kTBlock: cp = 6; break;
    case kOBlock: cp = 7; break;
  }

  if (cp) {
    wattron(w, COLOR_PAIR(cp));

    //Since characters are half-width, we have to render twice
    //to make a square
    mvwaddch(w, y, 2*x  , ' ');
    mvwaddch(w, y, 2*x+1, ' ');

    wattroff(w, COLOR_PAIR(cp));
  }
}

void front_ncurses::render_piece(WINDOW *w, Piece p, int y, int x) {
  int x_coords[p.max_num_blocks];
  int y_coords[p.max_num_blocks];
  p.get_coords(x_coords, y_coords);

  for (int i = 0; i < p.max_num_blocks; i++) {
    render_block(w, y - y_coords[i], x/2 + x_coords[i], p.get_type());
  }
}

void front_ncurses::render_board(GameBoard gb) {

  //Clear the board
  werase(gameboard_win);
  box(gameboard_border_win, 0, '#');

  //Render the blocks on the gameboard
  for (int y = 0; y < gb.num_visible_rows; y++) {
    for (int x = 0; x < gb.num_cols; x++) {
      BlockType bt = gb.get_block_type_at(y, x);
      //y-coordinate has to be inverted
      front_ncurses::render_block(gameboard_win,
          gb.num_visible_rows-1-y, x, bt);
    }
  }

  //Render the active piece
  int active_y, active_x;
  gb.get_active_piece_yx(active_y, active_x);
  render_piece(gameboard_win, gb.get_active_piece(), 
      gb.num_visible_rows - 1 - active_y, //since coords are stored bottom-up
      active_x * 2);                      //since blocks are 2 chars wide
  
  werase(game_info_win);

  //Print score and other information
  mvwprintw(game_info_win, 0, 0, "Score:");
  mvwprintw(game_info_win, 3, 0, "Level:");
  mvwprintw(game_info_win, 6, 0, "Lines:");
  mvwprintw(game_info_win, 9, 0, "Next:");

  //Show the next piece
  render_piece(game_info_win, gb.get_next_piece(), 12, 4);

  //Update window
  wrefresh(gameboard_border_win);
  wrefresh(game_info_win);
  wrefresh(gameboard_win);
}

void front_ncurses::handle_input(GameBoard& gb) {
  timeout(200);
  int inp = getch();
  switch(inp) {
    case KEY_LEFT:  gb.move_active_piece(1, -1); break;
    case KEY_RIGHT: gb.move_active_piece(1,  1); break;
    default:        gb.move_active_piece(1,  0);
  }
}

void front_ncurses::wait_for_input() {
  timeout(-1);
  getch();
}

void front_ncurses::quit() {
  delwin(gameboard_win);
  endwin();
}
