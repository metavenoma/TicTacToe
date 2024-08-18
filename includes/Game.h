#ifndef GAME_H
#define GAME_H

#ifdef __cplusplus
#extern "C"
{
#endif

#include "TicTacToe.h"

int	parseInput(char row, char col, int *x, int *y, int **board);
void	gameLoop(int **board);
void	runGame(void);

#ifdef __cplusplus
}
#endif

#endif
