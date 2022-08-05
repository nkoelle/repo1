
CC = gcc

CFLAGS = -Wall -Werror -Wextra -g
READLINE_LINK = -L /Users/$(USER)/.brew/opt/readline/lib
READLINE_INC = -I/Users/$(USER)/.brew/opt/readline/include
LIBFT_LINK = -L ./libft
L_FLAGS = -lft -lreadline

FLAGS = -g -Wall -Werror -Wextra -L ./libft -lft -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include

INCLUDES = minishell.h

SRC = Lexer/lexer.c\
	Lexer/signal.c\
	Parser/handle_special_char.c\
	Parser/parser.c\
	Parser/parser_helper.c\
	Parser/read_identifier.c\
	Utils/read_id_utils.c\
	Utils/add_char_or_str.c\
	Utils/parser_utils.c\
	Utils/stringbuilder.c\
	Utils/handle_list.c\
	Utils/add_list_to_list.c\
	Utils/input_list_handle.c\
	Utils/create_node.c\
	exe/exe_proto.c\
	exe/exe_builtin.c\
	exe/redir.c\
	exe/outsource.c\
	exe/exe_utils.c\
	exe/heredoc.c\
	exe/Env.c\
	exe/env_hidden.c\
	exe/export_helper.c\
	exe/export_helper2.c\
	exe/export_helper3.c\
	exe/convert_list_array.c\
	builtins/cd.c\
	builtins/echo.c\
	builtins/env.c\
	builtins/expand.c\
	builtins/exit.c\
	builtins/export.c\
	builtins/export_he.c\
	builtins/pwd.c\
	builtins/txt.c\
	builtins/unset.c\
	Utils/find_exec_path.c\
	Utils/exit_status.c

OBJ = $(patsubst %.c, %.o, $(SRC))

LIBFT = $(MAKE) -C ./libft

OBJS = $(SRC:.c=.o)

NAME = minishell

all: $(NAME)
$(NAME): $(OBJ)
	$(LIBFT) 
	$(CC) $(OBJ) $(READLINE_LINK) $(READLINE_INC) $(CFLAGS) $(LIBFT_LINK) $(L_FLAGS)  -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(READLINE_INC) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rm -f *.a
	rm -f *.o
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	rm -f *.o
	make fclean -C ./libft

re: fclean all

norm:
	norminette $(SRC) minishell
