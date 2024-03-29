#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define BOARD_SIZE 3
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;
    printf("\t .................................................\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        printf("\t .................................................\n");
    }
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE])
{
    board = board;
    char winner = '-';

    bool f;
    bool c;
    bool d = true;
    bool e = true;
    char eChar = board[BOARD_SIZE-1][0];
    // IMPLEMENTAR
    
    for(int i = 0; i < BOARD_SIZE; i++){
        
        c = true;
        f= true;
        for(int j = 0; j < BOARD_SIZE-1; j++){
            f = f && (board[i][j] == board[i][j+1]);
            c = c && (board[j][i] == board[j+1][i]);

            if(i == j && i < BOARD_SIZE && j < BOARD_SIZE) d = d && (board[i][j] == board[i+1][j+1]);
            
            if(i + j+1 == BOARD_SIZE-1) {
                printf("Comp %c == %c \n", board[i][j+1], eChar);
                e = e && (board[i][j+1] == eChar);
            }
        }

        if(f && board[i][0] != '-') return board[i][0];

        if(c && board[0][i] != '-') return board[0][i];
    }

    if(d && board[0][0] != '-') return board[0][0];

    if(e && board[BOARD_SIZE-1][0] != '-') return board[BOARD_SIZE-1][0];

    return winner;
}

bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
    board = board;

    // IMPLEMENTAR
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] == '-') return true;
        }
    }

    return false;
}

int main(void)
{
    printf("TicTacToe [CoMpLeTo :')]\n");

    char board[BOARD_SIZE][BOARD_SIZE] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al 8): ",
               turn);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
