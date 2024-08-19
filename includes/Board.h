#ifndef BOARD_H
#define BOARD_H

#define FALSE 0
#define TRUE 1
#define BOARD_ERROR -1
#define GRID_SIZE 3

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

int	initBoard(int **board);
void	resetBoard(int **board);
void	printHeader(void);
void	printRestart(void);
void	printGoodBye(void);
void	printWinner(int player);
void	printBoard(int **board);

extern void *(*ttt_calloc)(size_t, size_t);

#ifdef __cplusplus
}
#endif

#endif
