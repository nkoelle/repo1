# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 16:41:30 by nkolle            #+#    #+#              #
#    Updated: 2021/09/22 16:33:11 by nkolle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
RM = rm
RM_FLAGS = -f

SOURCES = ft_printf.c ft_putchar.c ft_putptr.c \
			ft_putstr.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CC_FLAGS) -c $(SOURCES)
	ar -crs $(NAME) $(OBJECTS)

clean:
	$(RM) $(RM_FLAGS) $(OBJECTS)

fclean: clean
	$(RM) $(RM_FLAGS) $(NAME)

re: fclean all