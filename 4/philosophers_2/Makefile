CC = gcc

FLAGS = -Wall -Werror -Wextra -g

INCLUDES = philo.h

SRC = SRC/philo.c\
	SRC/create_philos.c\
	SRC/eat.c\
	SRC/time.c\
	SRC/routine.c\
	Utils/philo_utils.c

OBJS = $(SRC:.c=.o)

NAME = philo

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
	norminette $(SRC) philo.h