#include "Game.h"

void	runGame(void)
{
	t_board	*board;
	
	board = (t_board *)malloc(sizeof(t_board));	
	if (!initBoard(board, MAX_GRID_SIZE))
	{
		printf("ERROR: COULD NOT CREATE BOARD\n");
		return ;
	}
	printBoard(board);
	exitGame(board);
	return ;
}
