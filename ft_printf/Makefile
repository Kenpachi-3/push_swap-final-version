# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/15 14:41:43 by ntshuma           #+#    #+#              #
#    Updated: 2026/08/03 17:39:21 by ntshuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I ../libft
SRCS		= 	ft_printf.c\
				ft_print_char.c\
				ft_print_str.c\
				ft_print_int.c\
				ft_print_deci.c\
				ft_print_hexa.c\
				ft_print_ptr.c\
				ft_print_percent.c\
				ft_handle_specifier.c
HEADER		= ft_printf.h
OBJS		= $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

.SILENT: