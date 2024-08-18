#include "GameOver.h"

int	checkWinCondition(t_board *board)
{
	if (board->_matrix[0][0] != 0
		&& board->_matrix[0][0] == board->_matrix[1][1]
		&& board->_matrix[0][0] == board->_matrix[2][2])
		return (TRUE);
	if (board->_matrix[2][0] != 0
		&& board->_matrix[2][0] == board->_matrix[1][1]
		&& board->_matrix[2][0] == board->_matrix[0][2])
		return (TRUE);
	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (board->_matrix[0][i] != 0
			&& board->_matrix[0][i] == board->_matrix[1][i]
			&& board->_matrix[0][i] == board->_matrix[2][i])
			return (TRUE);
		if (board->_matrix[i][0] != 0
			&& board->_matrix[i][0] == board->_matrix[i][1]
			&& board->_matrix[i][0] == board->_matrix[i][2])
			return (TRUE);
	}
	return (FALSE);
}
