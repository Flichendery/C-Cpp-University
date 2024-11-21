#ifndef GAME_H
#define GAME_H

#include "sudoku.h"

void clear_screen();
void start_game(SudokuGrid *grid, Position cursor);
void display_grid(const SudokuGrid *grid, Position cursor);
int check_and_display_result(SudokuGrid *grid);

// Добавляем объявления функций
void clear_screen_br();
void cross_platform_sleep(int milliseconds);

#endif
