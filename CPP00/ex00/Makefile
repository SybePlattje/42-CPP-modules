NAME = megaphone

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo Done Compiling!

%.o: %.cpp
	@$(CC) $(CFLAGS) -c -o $@ $^
clean:
	@rm -rf $(OBJ)
	@echo Deleted objects!

fclean: clean
	@rm -rf $(NAME)
	@echo Deleted name!

re: fclean all

.PHONY: all clean fclean re