#ifndef BOARD_H
#define BOARD_H

#define FALSE 0
#define TRUE 1
#define BOARD_ERROR -1
#define MAX_GRID_SIZE 3

#ifdef __cplusplus
extern "C" {
#endif

#include "TicTacToe.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_board
{
	int	_grid;
	int	**_matrix;
}	t_board;

int	initBoard(t_board *board, int grid);
void	printBoard(t_board *board);

extern void *(*ttt_calloc)(size_t, size_t);

#ifdef __cplusplus
}
#endif

#endif
