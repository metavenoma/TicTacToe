#include "GameOver.h"

int	checkWinCondition(int **board)
{
	if (board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2])
		return (board[0][0] == PLAYER_1 ? PLAYER_1 : PLAYER_2);
	if (board[2][0] != 0 && board[2][0] == board[1][1] && board[2][0] == board[0][2])
		return (board[2][0] == PLAYER_1 ? PLAYER_1 : PLAYER_2);
	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (board[0][i] != 0 && board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return (board[0][i] == PLAYER_1 ? PLAYER_1 : PLAYER_2);
		if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][0] == board[i][2])
			return (board[i][0] == PLAYER_1 ? PLAYER_1 : PLAYER_2);
	}
	return (FALSE);
}

int	isGameOver(int **board)
{
	for (int row = 0; row < GRID_SIZE; row++)
	{
		for (int col = 0; col < GRID_SIZE; col++)
		{
			if (board[row][col] == 0)
				return (FALSE);
		}
	}
	return (TRUE);
}

int	checkGameState(int **board)
{
	int	winner = checkWinCondition(board);
	if (winner)
	{
		switch (winner)
		{
			case PLAYER_1:
				printf("PLAYER 1 WINS!\n");
				break ;
			case PLAYER_2:
				printf("PLAYER 2 WINS!\n");
				break ;
		}
		return (END_STATE);
	}
	if (isGameOver(board))
	{
		printf("IS A DRAW :/\n");
		return (END_STATE);
	}
	return (RUNNING_STATE);
}
