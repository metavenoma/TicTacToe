#include "../includes/Board.h"

void *(*ttt_calloc)(size_t, size_t) = calloc;

int	initBoard(t_board *board, int grid)
{
	if (grid < 3 || grid > MAX_GRID_SIZE)
	{
		board->_matrix = NULL;
		return (FALSE);
	}	
	board->_grid = grid;
	board->_matrix = (int **)ttt_calloc(board->_grid, sizeof(int *));
	if (board->_matrix == NULL)
		return (BOARD_ERROR);
	for (int i = 0; i < board->_grid; i++)
	{
		board->_matrix[i] = (int *)ttt_calloc(board->_grid, sizeof(int *));
		if (board->_matrix[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				free(board->_matrix[j]);
			}
			free(board->_matrix);
			return (BOARD_ERROR);
		}
	}
	return (TRUE);
}
