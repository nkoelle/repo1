# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 07:39:26 by olgerret          #+#    #+#              #
#    Updated: 2021/07/24 07:52:35 by olgerret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putnbr_hexa_fd.c ft_putnbr_unsigned_fd.c \
	ft_putchar_counter_fd.c ft_putnbr_counter_fd.c ft_putstr_counter_fd.c \


all: $(NAME)

$(NAME): *.c
	Make -C ./libft
	cp ./libft/libft.a $(NAME)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o

clean:
	rm -f ./libft/*.o
	rm -f *.o

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME)

re: fclean $(NAME)
