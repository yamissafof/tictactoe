#include "morpion.h"
#include <stdio.h>

void printBoard(char board[9]) {
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

void initializeBoard(char board[9]) {
    for (int i = 0; i < 9; i++) {
        board[i] = '1' + i;
    }
}
