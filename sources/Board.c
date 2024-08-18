#include "Board.h"

void *(*ttt_calloc)(size_t, size_t) = calloc;

int	initBoard(int **board)
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		board[i] = (int *)ttt_calloc(GRID_SIZE, sizeof(int *));
		if (board[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				free(board[j]);
			}
			free(board);
			return (BOARD_ERROR);
		}
	}
	return (TRUE);
}
