#include "Exit.h"

void	exitGame(int **board)
{
	if (board != NULL)
	{
		for (int row = 0; row < GRID_SIZE; row++)
			free(board[row]);
		free(board);
	}
	exit(0);
}
