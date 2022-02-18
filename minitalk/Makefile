CC = gcc

FLAGS = -Wall -Werror -Wextra -g

INCLUDES = Minitalk.h

SRC = Utils/ft_atoi.c\
	Utils/ft_putnbr_fd.c\
	client/client.c

SRC_2 = server/server.c\
	Utils/ft_atoi.c\
	Utils/ft_putnbr_fd.c

OBJS = $(SRC:.c=.o)

OBJS_2 = $(SRC_2:.c=.o)

CLIENT = client

SERVER = server

%.o: %.c
	gcc -c $(FLAGS) $^ -o $@

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJS)
	# $(CC) -c $(FLAGS) $(SRC) -o $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o minitalk

$(SERVER): $(OBJS_2)
	# $(CC) -c $(FLAGS) $(SRC_2) -o $(OBJS_2)
	$(CC) $(FLAGS) $(OBJS_2) -o server_minitalk

clean: 
	rm -f $(OBJS) $(OBJS_2)

fclean: clean
	rm -f $(OBJS_2) $(OBJS) minitalk server_minitalk

re: fclean all

norm:
	norminette $(SRC) Push_swap.h
