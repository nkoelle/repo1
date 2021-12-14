CC = gcc

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address -L ./mlx -lmlx -L ./libft -lft -framework OpenGl -framework AppKit

INCLUDES = so_long.h

SRC = so_long.c\
ft_map.c\
ft_create_map_surface.c\
ft_so_long_utils.c\
get_next_line/get_next_line_utils.c\
get_next_line/get_next_line.c\

LIBFT = $(MAKE) -C ./libft

MLX = $(MAKE) -C ./mlx

OBJS = $(SRC:.c=.o)

NAME = so_long

all: $(NAME)
$(NAME):
	$(LIBFT) 
	$(MLX)
	$(CC) $(FLAGS) $(SRC) $^ -o $@

clean:
	rm -f $(OBJECTS)
	rm -f *.a
	make -C ./libft clean
	make -C ./mlx clean

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all