NAME = TicTacToe
TEST_NAME = test_board
OBJ_PATH = objects/
INC = -I ./includes

SRC = sources/main.c sources/Board.c sources/Game.c sources/printBoard.c
SRC += sources/Exit.c
SRC_OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

TEST_SRC = $(SRC) tests/boardTests.cpp
TEST_OBJ = $(addprefix $(OBJ_PATH), $(TEST_SRC:.cpp=.o) $(TEST_SRC:.c=.o))

CC = gcc
CPP = g++
CFLAGS = -std=c99 -Wall -Wextra -Werror -g
CPPFLAGS = -std=c++11 -Wall -Wextra -Werror -g

$(OBJ_PATH)%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH)%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< -o $@ $(INC)

$(NAME): $(SRC_OBJ)
	$(CC) $(CFLAGS) $(SRC_OBJ) $(INC) -o $(NAME)

all: $(NAME)

tests: $(TEST_OBJ)
	$(CPP) $(CPPFLAGS) $(TEST_OBJ) $(INC) -lgtest -lgtest_main -pthread -o $(TEST_NAME)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME) $(TEST_NAME)

re: fclean all
