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
	Utils/ft_split.c\
	Utils/ft_lstsize.c\
	operations/rotate_ra.c\
	operations/rotate_rb.c\
	operations/rev_rotate_rra.c\
	operations/rev_rotate_rrb.c\
	operations/push_pa.c\
	operations/push_pb.c\
	operations/swap_single_sa.c\
	operations/swap_single_sb.c\
	operations/rotate_both_rr.c\
	operations/rev_rotate_both_rrr.c\
	operations/swap_both_ss.c\
	sort/ft_cases.c\
	sort/ft_sorted.c\
	sort/ft_sort_3.c\
	sort/ft_sort_5.c\
	sort/ft_sort_100.c


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