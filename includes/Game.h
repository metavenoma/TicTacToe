#ifndef GAME_H
#define GAME_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TicTacToe.h"
#define	MAP_COL(col) (col - 65)
#define MAP_ROW(row) (row - 49)

int	getInput(char row, char col, int **board, int player);
int	resolveInput(int game_state, int **board);
void	gameLoop(int **board);
void	runGame(void);
int	isMovePossible(int **board, int x, int y);
void	placeMove(int **board, int x, int y, int player);
int	playerAction(int **board);

#ifdef __cplusplus
}
#endif

#endif
