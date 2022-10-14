NAME = ./Animal

CC = c++

CFLAGS = -Wall -Werror -Wextra -Wshadow -std=c++98

SRC = src/main.cpp src/Dog.cpp src/Cat.cpp

OBJ :=  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	
	make fclean
	make all