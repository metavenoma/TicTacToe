#include "Board.h"
#include "Exit.h"

int	parseInput(char row, char col, int *x, int *y, int **board)
{
	if (row == 'X' && col == 'X')
		exitGame(board);
	*x = col - 'A';
	*y = row - '1';
	if (*y >= 0 && *y < GRID_SIZE && *x >= 0 && *x < GRID_SIZE)
		return TRUE;
	return FALSE;
}
