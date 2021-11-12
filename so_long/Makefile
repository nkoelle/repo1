CC = gcc

NAME = so_long

FLAGS = -Wall -Wextra -Werror

SRC = so_long.c

MLX = ./mlx/libmlx.a


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)