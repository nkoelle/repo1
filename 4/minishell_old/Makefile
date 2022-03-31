CC = gcc

FLAGS = -Wall -Werror -Wextra -L ./libft -lft -lreadline -L /Users/nkolle/.brew/opt/readline/lib -I/Users/nmichael/.brew/opt/readline/include

# DEBUGTHISSHIT = -fsanitize=address

INCLUDES = minishell.h

SRC = Lexer/lexer.c\
	Parser/handle_special_char.c\
	Parser/parser.c\
	Parser/read_identifier.c\
	Utils/read_id_utils.c\
	Utils/handle_list.c\
	Utils/create_node.c


LIBFT = $(MAKE) -C ./libft

OBJS = $(SRC:.c=.o)

NAME = minishell

all: $(NAME)
$(NAME):
	$(LIBFT) 
	$(CC) $(FLAGS) $(DEBUGTHISSHIT) $(SRC) $^ -o $@

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