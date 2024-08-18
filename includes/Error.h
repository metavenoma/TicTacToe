#ifndef ERROR_H
#define ERROR_H

#define BOARD_ERROR -1
#define MOVE_ERROR -2
#define NEXT_STATE 131
#define EXIT_CODE 130
#define RESTART_CODE 129
#define INVALID_INPUT 128

#define BOARD_ERROR_MSG "Error: Board: Could not create Board."
#define MOVE_ERROR_MSG "Error: Space is not available."

#include <stdio.h>

void	clearBoard(int **board);
void	errorHandling(int error_code);

#endif 
