#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Board.h"
#include "Game.h"

#define PLAYER_1 1
#define PLAYER_2 2
#define END_STATE 64
#define RUNNING_STATE 65

int	checkWinCondition(int **board);
int	isGameOver(int **board);
int	checkGameState(int **board);

#endif
