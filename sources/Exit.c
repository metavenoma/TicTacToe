#include "Exit.h"

void	exitGame(t_board *board)
{
	if (board != NULL)
	{
		if (board->_matrix != NULL)
		{
			for (int row = 0; row < MAX_GRID_SIZE; row++)
				free(board->_matrix[row]);
			free(board->_matrix);
			free(board);
		}
	}
	return ;
}
