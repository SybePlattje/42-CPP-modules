NAME = animals

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g 
CC = c++

INCLUDE_DIR = ./include
SRC_DIR = ./src
HEADERS = $(INCLUDE_DIR)/Animal.hpp \
		$(INCLUDE_DIR)/Cat.hpp \
		$(INCLUDE_DIR)/Dog.hpp \
		$(INCLUDE_DIR)/WrongAnimal.hpp \
		$(INCLUDE_DIR)/WrongCat.hpp \

SRC = $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/Animal.cpp \
	$(SRC_DIR)/Cat.cpp \
	$(SRC_DIR)/Dog.cpp \
	$(SRC_DIR)/WrongAnimal.cpp \
	$(SRC_DIR)/WrongCat.cpp \

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