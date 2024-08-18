#include "GameOver.h"

int	checkWinCondition(t_board *board)
{
	if (board->_matrix[0][0] != 0
		&& board->_matrix[0][0] == board->_matrix[1][1]
		&& board->_matrix[0][0] == board->_matrix[2][2])
		return (board->_matrix[0][0] == PLAYER_1 ? PLAYER_1 : PLAYER_2);
	if (board->_matrix[2][0] != 0
		&& board->_matrix[2][0] == board->_matrix[1][1]
		&& board->_matrix[2][0] == board->_matrix[0][2])
		return (board->_matrix[2][0] == PLAYER_1 ? PLAYER_1 : PLAYER_2);
	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (board->_matrix[0][i] != 0
			&& board->_matrix[0][i] == board->_matrix[1][i]
			&& board->_matrix[0][i] == board->_matrix[2][i])
			return (board->_matrix[0][i] == PLAYER_1 ? PLAYER_1 : PLAYER_2);
		if (board->_matrix[i][0] != 0
			&& board->_matrix[i][0] == board->_matrix[i][1]
			&& board->_matrix[i][0] == board->_matrix[i][2])
			return (board->_matrix[i][0] == PLAYER_1 ? PLAYER_1 : PLAYER_2);
	}
	return (FALSE);
}

int	isGameOver(t_board *board)
{
	for (int row = 0; row < GRID_SIZE; row++)
	{
		for (int col = 0; col < GRID_SIZE; col++)
		{
			if (board->_matrix[row][col] == 0)
				return (FALSE);
		}
	}
	return (TRUE);
}
