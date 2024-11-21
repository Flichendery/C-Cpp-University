#include <stdio.h>
#include <stdlib.h>
#include "sudoku_all.h"

// Очистка экрана (использование ifdef для кроссплатформенной работы)
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Запуск игры
void start_game(SudokuGrid *grid, Position cursor) {
    int game_over = 0;
    char input;

    // Первое отображение сетки
    clear_screen();
    display_grid(grid, cursor);

    while (!game_over) {
    
        printf("WASD to move, Enter 1-9, C to clear cursor, Q to quit: ");
        scanf(" %c", &input);  // Считываем символ нужной операции

        if (input == 'q' || input == 'Q') {
            printf("Exiting the game.\n");
            break;
        } else if (input == 'c' || input == 'C') {
            // Очистка выбранной ячейки
            if (*(*((*grid).cells + cursor.row) + cursor.col) <= 0) {
                *(*((*grid).cells + cursor.row) + cursor.col) = 0;
            } else {
                printf(RED "Cannot clear a pre-filled cell.\n" RESET);
            }
        } else if (input >= '1' && input <= '9') {
            int num = input - '0';  // Преобразование символа в число
            if (num > 0 && num <= (*grid).size) {
                // Проверяем где ставится цифра, можно ставить только в пустых местах, либо где игрок поставил цифру
                if (*(*((*grid).cells + cursor.row) + cursor.col) <= 0) {
                    *(*((*grid).cells + cursor.row) + cursor.col) = -num;
                }
            }
        } else if (input == 'w' || input == 'W') {
            if (cursor.row > 0) cursor.row--;
        } else if (input == 's' || input == 'S') {
            if (cursor.row < (*grid).size - 1) cursor.row++;
        } else if (input == 'a' || input == 'A') {
            if (cursor.col > 0) cursor.col--;
        } else if (input == 'd' || input == 'D') {
            if (cursor.col < (*grid).size - 1) cursor.col++;
        } else {
            printf("Invalid input. Try again.\n");
        }

        // Очистка экрана и отображение обновлённой сетки
        clear_screen();
        display_grid(grid, cursor);

        // Проверка, заполнены ли все ячейки
        int filled_cells = 1;
        for (sudoku_size i = 0; i < (*grid).size; i++) {
            for (sudoku_size j = 0; j < (*grid).size; j++) {
                if (*(*((*grid).cells + i) + j) == 0) {
                    filled_cells = 0;
                    break;
                }
            }
            if (!filled_cells) break;
        }

        // Если все ячейки заполнены, проверяем результат
        if (filled_cells) {
            printf("\n");
            game_over = check_and_display_result(grid);
            if (game_over) {
                printf(GREEN "\nCongratulations! Sudoku is solved correctly!\n" RESET);
            } else {
                printf(RED "\nSome numbers are wrong. Try again.\n" RESET);
            }
        }
    }
}

// Отображение сетки игры
void display_grid(const SudokuGrid *grid, Position cursor) {
    int box_size = ((*grid).size == 9) ? 3 : 2;

    for (sudoku_size i = 0; i < (*grid).size; i++) {
        for (sudoku_size j = 0; j < (*grid).size; j++) {
            int cell = *(*((*grid).cells + i) + j);

            if (i == cursor.row && j == cursor.col) {
                // Если выделено пустое место
                if (cell == 0) {
                    printf(BLUE "[.]" RESET);
                } else {
                    printf(BLUE "[%d]" RESET, abs(cell));
                }
            } else if (cell < 0) {
                printf(CYAN " %d " RESET, abs(cell));
            } else if (cell > 0) {
                printf(WHITE " %d " RESET, cell);
            } else {
                printf(" . ");
            }
        
        // Разметка поля
            if ((j + 1) % box_size == 0 && j + 1 != (*grid).size) {
                printf(" | ");
            }
        }
        printf("\n");

        if ((i + 1) % box_size == 0 && i + 1 != (*grid).size) {
            int cell_width = 3;
            int line_length = (*grid).size * cell_width + (box_size - 1) * 3;
            for (sudoku_size k = 0; k < line_length; k++) {
                printf("=");
            }
            printf("\n");
        }
    }
}



// Проверка и отображение результата
int check_and_display_result(SudokuGrid *grid) {
    int correct = 1;
    int box_size = ((*grid).size == 9) ? 3 : 2;

    for (sudoku_size i = 0; i < (*grid).size; i++) {
        for (sudoku_size j = 0; j < (*grid).size; j++) {
            int num = abs(*(*((*grid).cells + i) + j));

            if (*(*((*grid).cells + i) + j) < 0) {
                if (is_valid_move(grid, i, j, num)) {
                    printf(GREEN " %d " RESET, num);  // Правильная цифра
                } else {
                    printf(RED " %d " RESET, num);  // Неправильная цифра
                    correct = 0;
                }
            } else if (num != 0) {
                printf(" %d ", num);
            } else {
                printf(" . ");
            }

        // Разметка поля
            if ((j + 1) % box_size == 0 && j + 1 != (*grid).size) {
                printf(" | ");
            }
        }
        printf("\n");

        if ((i + 1) % box_size == 0 && i + 1 != (*grid).size) {
            int cell_width = 3;
            int line_length = (*grid).size * cell_width + (box_size - 1) * 3;
            for (sudoku_size k = 0; k < line_length; k++) {
                printf("=");
            }
            printf("\n");
        }
    }
    return correct;
}
