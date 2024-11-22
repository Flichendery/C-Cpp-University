#ifndef SUDOKU_ALL_H
#define SUDOKU_ALL_H

// Цвета
#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"

// Псевдотипы
typedef enum {
    FOUR_BY_FOUR = 4,
    NINE_BY_NINE = 9
} GridSize;

typedef unsigned int sudoku_size;

typedef struct {
    sudoku_size size;
    int **cells;
} SudokuGrid;

typedef struct {
    sudoku_size row;
    sudoku_size col;
} Position;

// Объявление функций
// sudoku.c
void initialize_grid(SudokuGrid *grid, GridSize size);
void generate_initial_grid(SudokuGrid *grid);
int is_valid_move(SudokuGrid *grid, sudoku_size row, sudoku_size col, int num);
void free_grid(SudokuGrid *grid);

// game.c
void clear_screen();
void start_game(SudokuGrid *grid, Position cursor);
void display_grid(const SudokuGrid *grid, Position cursor);
int check_and_display_result(SudokuGrid *grid);
void my_sleep(int milliseconds);

// bruteforce.c
int run_bruteforce(SudokuGrid *grid);

#endif