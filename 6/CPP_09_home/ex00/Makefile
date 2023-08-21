NAME = ./btc

CC = c++

CFLAGS = -Wall -Werror -Wextra -Wshadow -g -std=c++98

SRC = src/main.cpp src/BitcoinExchange.cpp

OBJ =  $(patsubst %.cpp, %.o, $(SRC))

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf *.txt

fclean: clean
	rm -rf $(NAME)

re:	
	make fclean
	make all