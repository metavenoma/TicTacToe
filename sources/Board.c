#include "Board.h"

void *(*ttt_calloc)(size_t, size_t) = calloc;

void	resetBoard(int **board)
{
	for (int row = 0; row < GRID_SIZE; row++)
	{
		for (int col = 0; col < GRID_SIZE; col++)
			board[row][col] = 0;
	}
}

int	initBoard(int **board) {
    if (board == NULL) {
        return BOARD_ERROR; // Allocation failed
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        // Allocate memory for each row
        board[i] = (int *)ttt_calloc(GRID_SIZE, sizeof(int));
        if (board[i] == NULL) {
            // Free previously allocated rows
            for (int j = 0; j < i; j++) {
                free(board[j]);
            }
            free(board);
            return BOARD_ERROR; // Allocation failed
        }
    }
    return TRUE; // Success
}
