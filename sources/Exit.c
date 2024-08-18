#include "Exit.h"

void	exitGame(t_board *board)
{
	if (board != NULL)
	{
		if (board->_matrix != NULL)
		{
			for (int row = 0; row < GRID_SIZE; row++)
				free(board->_matrix[row]);
			free(board->_matrix);
			free(board);
		}
	}
	exit(0);
}
