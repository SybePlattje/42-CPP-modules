NAME = interface

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
CC = c++

INCLUDE_DIR = ./includes
SRC_DIR = ./src
HEADERS = $(INCLUDE_DIR)/AMateria.hpp \
		$(INCLUDE_DIR)/Character.hpp \
		$(INCLUDE_DIR)/Cure.hpp \
		$(INCLUDE_DIR)/Ice.hpp \
		$(INCLUDE_DIR)/ICharacter.hpp \
		$(INCLUDE_DIR)/IMateriaSource.hpp \
		$(INCLUDE_DIR)/MateriaSource.hpp \

SRC = $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/AMateria.cpp \
	$(SRC_DIR)/Character.cpp \
	$(SRC_DIR)/Cure.cpp \
	$(SRC_DIR)/Ice.cpp \
	$(SRC_DIR)/MateriaSource.cpp \

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