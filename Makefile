# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 14:43:46 by anovio-c          #+#    #+#              #
#    Updated: 2024/01/26 11:07:56 by anovio-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h

SRCS =	ft_utils_pf.c		\
		ft_printf.c			\
		ft_putchar_pf.c		\
		ft_putstr_pf.c		\
		ft_putnbr_pf.c		\
		ft_putadress_pf.c	\
		ft_puthex_pf.c		\
		ft_putunsigned.c

OBJS = $(SRCS:.c=.o)

LIB = ar -rcs
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):	$(OBJS) Makefile $(HEADER)
			$(LIB) $(NAME) $(OBJS)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
