#include <gtest/gtest.h>
extern "C" 
{
	#include "Game.h"  // Include the C header
}

TEST(ParseInputTest, ValidInput) 
{
	int x, y;
	int **board = nullptr;
	ASSERT_TRUE(parseInput('1', 'A', &x, &y, board));  // Example valid input
	ASSERT_EQ(x, 0);
	ASSERT_EQ(y, 0);
}

TEST(ParseInputTest, InvalidInput) 
{
	int x, y;
	int **board = nullptr;
	ASSERT_FALSE(parseInput('#', 'D', &x, &y, board));  // Example invalid input
}

TEST(ParseInputTest, EdgeCases) 
{
	int x, y;
	int **board = nullptr;
	ASSERT_FALSE(parseInput('D', '1', &x, &y, board));  // Example invalid edge case
	ASSERT_FALSE(parseInput('A', '4', &x, &y, board));  // Example invalid edge case
}
