CC = gcc

NAME = minitalk

FLAGS = -Wall -Werror -Wextra -g

INCLUDES = Minitalk.h

SRC = Utils/ft_atoi.c\
	Utils/ft_putnbr_fd.c\
	Client/client.c

SRC_2 = Server/server.c\
	Utils/ft_atoi.c\
	Utils/ft_putnbr_fd.c

OBJS = $(SRC:.c=.o)

OBJS_2 = $(SRC_2:.c=.o)

CLIENT = client

SERVER = server

%.o: %.c
	gcc -c $(FLAGS) $< -o $@


$(NAME): $(OBJS) $(OBJS_2)
	$(CC) $(FLAGS) -o minitalk $(OBJS)
	$(CC) $(FLAGS) -o server_minitalk $(OBJS_2)

all: $(NAME)

$(CLIENT): $(OBJS)
	$(CC) $(FLAGS) -o minitalk $(OBJS)

$(SERVER): $(OBJS_2)
	$(CC) $(FLAGS) -o server_minitalk $(OBJS_2)

clean: 
	rm -f $(OBJS) $(OBJS_2)

fclean: clean
	rm -f minitalk server_minitalk

re: fclean $(OBJS_2) $(OBJS)
	$(CC) $(FLAGS) -o server_minitalk $(OBJS_2)
	$(CC) $(FLAGS) -o minitalk $(OBJS)

norm:
	norminette $(SRC) minitalk.h
