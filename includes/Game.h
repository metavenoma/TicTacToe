#ifndef GAME_H
#define GAME_H

#ifdef __cplusplus
#extern "C"
{
#endif

#include "TicTacToe.h"

typedef struct s_game
{
	int	ac;
	char	**av;
}	t_game;

int	parseInput(char row, char col, int *x, int *y, t_board *board);
void	gameLoop(t_board *board);
void	runGame(void);

#ifdef __cplusplus
}
#endif

#endif
