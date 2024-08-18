#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Board.h"
#include "Game.h"

#define PLAYER_1 1
#define PLAYER_2 2

void	winLoseScreen(int player);
void	drawScreen(void);
int	checkWinCondition(int **board);
int	isGameOver(int **board);

#endif
