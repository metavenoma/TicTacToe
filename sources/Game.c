#include "Game.h"
#include "GameOver.h"

void	runGame(void)
{
	t_board	*board;
	
	board = (t_board *)malloc(sizeof(t_board));	
	if (!initBoard(board, GRID_SIZE))
	{
		printf("ERROR: COULD NOT CREATE BOARD\n");
		return ;
	}
	printBoard(board);
	gameLoop(board);
	exitGame(board);
	return ;
}

int	isMovePossible(t_board *board, int x, int y)
{
	return (board->_matrix[x][y] == 0);
}

void	placeMove(t_board *board, int x, int y, int player)
{
	board->_matrix[x][y] = player;
}

void	gameLoop(t_board *board)
{
	int	player = 1;
	char	row, col;
	int	x = 0, y = 0;

	while (1)
	{
		printBoard(board);
		printf("Player %d, enter your move (e.g., A3): ", player);
		col = getchar();
		row = getchar();
		getchar();

		if (parseInput(row, col, &x, &y, board) == TRUE
				&& isMovePossible(board, x, y))
		{
			placeMove(board, x, y, player);
			player = (player == 1) ? 2 : 1;
			if (checkWinCondition(board))
			{
				printf("\n\nWIN\n\n");
				break ;
			}
		}
	}
	exitGame(board);
}
