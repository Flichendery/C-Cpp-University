#include <stdlib.h>
#include <time.h>
#include "sudoku_all.h"

// Определяем функции из других файлов
void generate_initial_grid(SudokuGrid *grid);
int is_valid_move(SudokuGrid *grid, sudoku_size row, sudoku_size col, int num);
int bruteforce(SudokuGrid *grid, sudoku_size row, sudoku_size col);
int brute_hide(SudokuGrid *grid, sudoku_size row, sudoku_size col);

// Инициализация поля
void initialize_grid(SudokuGrid *grid, GridSize size) {
    (*grid).size = size;
    (*grid).cells = (int **)malloc(size * sizeof(int *)); // Выделение памяти без инициализации пустого пространства
    for (sudoku_size i = 0; i < size; i++) {
        *((*grid).cells + i) = (int *)calloc(size, sizeof(int)); // Выделение памяти с инициализацией пустого пространства в виде нулей
    }
    generate_initial_grid(grid);
}

void generate_initial_grid(SudokuGrid *grid) {
    srand(time(NULL));
    int clues = ((*grid).size == 9) ? 25 : 8;

    brute_hide(grid, 0, 0);

    int total_cells = (*grid).size * (*grid).size;
    int to_remove = total_cells - clues;

    while (to_remove > 0) {
        int row = rand() % (*grid).size;
        int col = rand() % (*grid).size;

        if (*(*((*grid).cells + row) + col) != 0) {
            *(*((*grid).cells + row) + col) = 0;
            to_remove--;
        }
    }
}

// Проверка на правильно поставленную цифру в конце игры
int is_valid_move(SudokuGrid *grid, sudoku_size row, sudoku_size col, int num) {
    int subgrid_size = ((*grid).size == 9) ? 3 : 2;

    for (sudoku_size i = 0; i < (*grid).size; i++) {
        if (*(*((*grid).cells + row) + i) == num || *(*((*grid).cells + i) + col) == num)
            return 0;
    }

    int start_row = (row / subgrid_size) * subgrid_size;
    int start_col = (col / subgrid_size) * subgrid_size;

    for (sudoku_size i = 0; i < subgrid_size; i++) {
        for (sudoku_size j = 0; j < subgrid_size; j++) {
            if (*(*((*grid).cells + start_row + i) + start_col + j) == num)
                return 0;
        }
    }
    return 1;
}

// Проверка заполнены ли все поля игры
int is_solved(SudokuGrid *grid) {
    for (sudoku_size i = 0; i < (*grid).size; i++) {
        for (sudoku_size j = 0; j < (*grid).size; j++) {
            int num = *(*((*grid).cells + i) + j);
            if (num == 0 || !is_valid_move(grid, i, j, num)) {
                return 0;
            }
        }
    }
    return 1;
}

// Корректное освобождение динамического массива
void free_grid(SudokuGrid *grid) {
    for (sudoku_size i = 0; i < (*grid).size; i++) {
        free(*((*grid).cells + i));
    }
    free((*grid).cells);
}
