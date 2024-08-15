#include <gtest/gtest.h>
extern "C" 
{
	#include "../includes/Board.h"  // Include the C header
}

TEST(InitBoardTest, ValidGridSize) 
{
	t_board board;
	int grid_size = 3;
    
	ASSERT_EQ(initBoard(&board, grid_size), 1);  // Expect success (1)
    
	for (int i = 0; i < board._grid; i++) 
	{
		ASSERT_NE(board._matrix[i], nullptr);
	}
    
	// Free the allocated memory to avoid leaks
	for (int i = 0; i < board._grid; i++) 
	{
		free(board._matrix[i]);
	}
	free(board._matrix);
}

TEST(InitBoardTest, SmallGridSize) 
{
	t_board board;
	int grid_size = 1;
    
	ASSERT_EQ(initBoard(&board, grid_size), 0);  // Expect 0 for grid size < 2
	ASSERT_EQ(board._matrix, nullptr);
}

TEST(InitBoardTest, AllocationFailure) 
{
	t_board board;

	int grid_size = MAX_GRID_SIZE;  

	auto originalCalloc = ttt_calloc;
	ttt_calloc = [](size_t num, size_t size) -> void* 
	{
		return nullptr;  // Force allocation failure
	};

	ASSERT_EQ(initBoard(&board, grid_size), -1);  // Expect -1 if allocation fails
	ttt_calloc = originalCalloc;
}

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
