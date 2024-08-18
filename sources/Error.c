#include "Error.h"

void	errorHandling(int error_code)
{
	switch (error_code)
	{
		case BOARD_ERROR:
			printf("%s\n", BOARD_ERROR_MSG);
			break ;
		case MOVE_ERROR:
			printf("%s\n", MOVE_ERROR_MSG);
			break ;
		default:
			printf("Error\n");
			break ;
	}
}
