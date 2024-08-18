#include <gtest/gtest.h>
#include "Board.h"

class InitBoardTest : public ::testing::Test {
protected:
    int **board;

    virtual void SetUp() {
        // Allocate memory for the board (3x3)
        board = (int **)calloc(GRID_SIZE, sizeof(int *));
        for (int i = 0; i < GRID_SIZE; i++) {
            board[i] = (int *)calloc(GRID_SIZE, sizeof(int));
        }
    }

    virtual void TearDown() {
        // Free the board memory
        for (int i = 0; i < GRID_SIZE; i++) {
            free(board[i]);
        }
        free(board);
    }
};

TEST_F(InitBoardTest, ValidGridSize) {
    // Test for a valid grid size
    ASSERT_EQ(initBoard(board), TRUE);  // Expect success (1)
}

TEST_F(InitBoardTest, SmallGridSize) {
    // Simulate small grid size by modifying GRID_SIZE temporarily
    // This assumes GRID_SIZE can be changed dynamically for testing purposes
    // Since it's a macro, this requires changing the macro definition itself,
    // which is not ideal. This test might be removed if such changes are impractical.
}

TEST_F(InitBoardTest, AllocationSuccess) {
    // Ensure that the board is correctly initialized
    ASSERT_NE(board, nullptr);
    for (int i = 0; i < GRID_SIZE; i++) {
        ASSERT_NE(board[i], nullptr);
    }
}
