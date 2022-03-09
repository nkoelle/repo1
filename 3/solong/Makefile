CC = gcc

FLAGS = -Wall -Werror -Wextra -L ./mlx -lmlx -L ./libft -lft -framework OpenGl -framework AppKit

INCLUDES = so_long.h

SRC = so_long.c\
ft_map_alloc.c\
ft_map_error.c\
ft_create_map_surface.c\
ft_start_game.c\
ft_move.c\
ft_so_long_utils.c

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

norm:
	norminette $(SRC) so_long.h \