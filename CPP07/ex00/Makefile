NAME = Template

CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g 

SRC_DIR = ./src
SRC = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_DIR = ./obj
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d);

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo Done Compiling!

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