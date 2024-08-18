#include "Game.h"
#include "GameOver.h"

void	runGame(void)
{
	int	**board;
	
	board = (int **)malloc(sizeof(int *) * GRID_SIZE);
	if (!board || !initBoard(board))
	{
		printf("ERROR: COULD NOT CREATE BOARD\n");
		return ;
	}
	printBoard(board);
	gameLoop(board);
	exitGame(board);
	return ;
}

int	isMovePossible(int **board, int x, int y)
{
	return (board[x][y] == 0);
}

void	placeMove(int **board, int x, int y, int player)
{
	board[x][y] = player;
}

void	gameLoop(int **board)
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
			if (isGameOver(board))
			{
				printf("\n\nDRAW\n\n");
				break ;
			}
			if (checkWinCondition(board))
			{
				printf("\n\nWIN\n\n");
				break ;
			}
		}
	}
	exitGame(board);
}
