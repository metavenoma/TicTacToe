#include "../includes/Board.h"


void	clearScreen(void)
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void	printBoard(t_board *board)
{
	int	grid = board->_grid;
	
	clearScreen();	
	printf("  ");
	
	for (int col = 0; col < grid; col++)
	{
		printf(" %c  ", 'A' + col);
	}
	printf("\n");

	for (int row = 0; row < grid; row++)
	{
		if (row == 0)
		{
			printf(" ");
			for (int col = 0; col < grid; col++)
			{
				printf(" ---");
			}
			printf("\n");
		}
		printf("%d", row + 1);
		for (int col = 0; col < grid; col++)
		{
			printf("| %c ", board->_matrix[row][col] == 0 ? ' ' : (board->_matrix[row][col] == 1 ? 'X' : 'O'));
		}
		printf("|\n");

		printf(" ");
		for (int col = 0; col < grid; col++)
		{
			printf(" ---");
		}
		printf("\n");
	}
}
