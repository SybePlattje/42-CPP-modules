NAME = convert

CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g

SRC_DIR = ./src
SRC = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_DIR = ./obj
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d);

$(shell mkdir -p $(OBJ_DIR))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo Done Compiling!
	@echo To execute run ./$(NAME) ARGUMENT

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
	@rm -fr $(OBJ_DIR)
	@echo Deleted Objects!

fclean: clean
	@rm -f $(NAME)
	@echo Deleted Program!

re: fclean all

.PHONY: all clean fclean re