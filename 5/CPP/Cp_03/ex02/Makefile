NAME = FragTrap

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJ :=  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	
	make fclean
	make all