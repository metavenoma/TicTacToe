#include "Game.h"
#include "GameOver.h"
#include "Error.h"

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

void	clearInputBuffer(void)
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
		;
}

int	playerAction(int **board)
{
	static int	player = 1;
	char		row, col;
	
	printf("Player %d, enter your move (e.g., A3): ", player);
	col = getchar();
	row = getchar();

	int	game_state = getInput(row, col, board, player);
	if (resolveInput(game_state, board) == NEXT_STATE)
		player = (player == 1) ? 2 : 1;
	printBoard(board);
	clearInputBuffer();
	if (checkGameState(board) == END_STATE)
		exitGame(board);
	return (0);
}

void	gameLoop(int **board)
{
	printHeader();
	printBoard(board);
	while (1)
	{
		playerAction(board);
/*		error = checkGameState(board);
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
//		errorHandLing(error):
		else if (parseInput(row, col, &x, &y, board) == TRUE
				&& !isMovePossible(board, x, y))
			errorHandling(MOVE_ERROR);*/
	}
	exitGame(board);
}
