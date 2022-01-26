CC = gcc

FLAGS = -Wall -Werror -Wextra -g

INCLUDES = Push_swap.h

SRC = Push_swap.c\
	ft_error.c\
	Utils/Push_swap_utils.c\
	Utils/ft_lstlast_ps.c\
	Utils/ft_lstadd_front.c\
	Utils/ft_atoi.c\
	Utils/ft_strlen.c\
	Utils/ft_strdup.c\
	Utils/ft_isdigit.c\
	operations/rotate_ra.c\
	operations/rev_rotate_rra.c\
	operations/push_pa.c\
	operations/swap_single_sa.c\
	operations/rotate_both_rr.c\
	operations/rev_rotate_both_rrr.c\
	operations/swap_both_ss.c


OBJS = $(SRC:.c=.o)

NAME = Push_swap

all: $(NAME)
$(NAME):
	$(CC) $(FLAGS) $(SRC) $^ -o $@

clean:
	rm -f $(OBJECTS)
	rm -f *.a

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) Push_swap.h