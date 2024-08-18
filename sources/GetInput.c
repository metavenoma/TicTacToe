#include "Board.h"
#include "Exit.h"
#include "Error.h"
#include "Game.h"

int	getInput(char row, char col, int **board, int player)
{	
	if (row == 'X' && col == 'X')
		return EXIT_CODE;
	if (row == 'R' && col == 'R')
		return RESTART_CODE;
	int x = MAP_COL(col);
	int y = MAP_ROW(row);
	if (y >= 0 && y < GRID_SIZE && x >= 0 && x < GRID_SIZE)
	{
		if (isMovePossible(board, x, y))
		{
			placeMove(board, x, y, player);
			return NEXT_STATE;
		}
	}
	return INVALID_INPUT;
}

int	resolveInput(int game_state, int **board)
{
	switch (game_state)
	{
		case EXIT_CODE:
			printf("Goodbye!\n");
			exitGame(board);
			break ;
		case NEXT_STATE:
			printf("next state\n");
			return (game_state);
		case RESTART_CODE:
			resetBoard(board);
			printf("GAME RESTART\n");
			break ;
		case INVALID_INPUT:
			printf("INVALID INPUT, TRY <ROW><COLUMN> e.g. C2");
			break ;
	}
	return (FALSE);
}
