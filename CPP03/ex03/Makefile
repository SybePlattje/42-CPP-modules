NAME = DiamandTrap

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -Wshadow
CC = c++

INCLUDE_DIR = ./includes
SRC_DIR = ./src
HEADERS = $(INCLUDE_DIR)/ClapTrap.hpp \
		$(INCLUDE_DIR)/ScavTrap.hpp \
		$(INCLUDE_DIR)/FragTrap.hpp \
		$(INCLUDE_DIR)/DiamondTrap.hpp \

SRC = $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/ClapTrap.cpp \
	$(SRC_DIR)/ScavTrap.cpp \
	$(SRC_DIR)/FragTrap.cpp \
	$(SRC_DIR)/DiamondTrap.cpp \

OBJ_DIR = ./obj
$(shell mkdir -p $(OBJ_DIR))

OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@cp $(HEADERS) $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo Done Compiling!

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
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