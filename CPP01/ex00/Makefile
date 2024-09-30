NAME = zombie

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

SRC = main.cpp \
	newZombie.cpp \
	randomChump.cpp \
	Zombie.cpp \

OBJ_DIR = ./obj
$(shell mkdir -p $(OBJ_DIR))

OBJ = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo Done Compiling!

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo Deleted Objects!

fclean: clean
	@rm -rf $(NAME)
	@echo Deleted program!

re: fclean all

.PHONY: all clean fclean re