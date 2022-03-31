CC = gcc

FLAGS = -Wall -Werror -Wextra -L ./libft -lft -lreadline -L /Users/nkolle/.brew/opt/readline/lib -I/Users/nmichael/.brew/opt/readline/include

INCLUDES = minishell.h

SRC = Lexer/lexer.c\
	Parser/parser.c\
	Parser/check_char.c\
	Parser/parser_utils.c\
	Utils/add_str_to_buf_list.c\
	Utils/add_char_to_list.c\
	Utils/free_list.c\
	Utils/add_new_elem_to_buffer.c


LIBFT = $(MAKE) -C ./libft

OBJS = $(SRC:.c=.o)

NAME = minishell

all: $(NAME)
$(NAME):
	$(LIBFT) 
	$(CC) $(FLAGS) $(SRC) $^ -o $@

clean:
	rm -f $(OBJECTS)
	rm -f *.a
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

norm:
	norminette $(SRC) minishell.hmake