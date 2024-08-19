NAME = TicTacToe
TEST_NAME = testerTicTacToe
OBJ_PATH = objects/
INC = -I ./includes

# Source files and object file paths
SRC = sources/Board.c sources/Game.c sources/PrintBoard.c
SRC += sources/Exit.c sources/GetInput.c sources/GameOver.c
SRC += sources/Error.c
SRC_OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

# Object file paths for the main program
MAIN_SRC = sources/main.c
MAIN_OBJ = $(addprefix $(OBJ_PATH), $(MAIN_SRC:.c=.o))

# Test source files and object file paths
TEST_SRC = tests/BoardTester.cpp tests/ParseInputTester.cpp tests/main.cpp
TEST_OBJ = $(addprefix $(OBJ_PATH), $(TEST_SRC:.cpp=.o))

# Compilers and flags
CC = gcc
CPP = g++
CFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -Wall -Wextra -Werror -g

# Rules for creating object files
$(OBJ_PATH)%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH)%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< -o $@ $(INC)

# Build the main program
$(NAME): $(SRC_OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(SRC_OBJ) $(MAIN_OBJ) $(INC) -o $(NAME)

# Build the tests
tests: $(SRC_OBJ) $(TEST_OBJ)
	$(CPP) $(CPPFLAGS) $(TEST_OBJ) $(SRC_OBJ) -I ./includes -lgtest -lgtest_main -pthread -o $(TEST_NAME)

install: $(NAME) install_man

install_man:
	@bash install_man.sh

all: $(NAME)

# Clean up object files
clean:
	@rm -rf $(OBJ_PATH)

# Clean up and rebuild
fclean: clean
	@rm -f $(NAME) $(TEST_NAME)

# Rebuild everything
re: fclean all
