#ifndef GAME_H
#define GAME_H

#ifdef __cplusplus
#extern "C"
{
#endif

typedef struct s_game
{
	int	ac;
	char	**av;
}	t_game;

#include "TicTacToe.h"

void	runGame(void);

#ifdef __cplusplus
}
#endif

#endif
