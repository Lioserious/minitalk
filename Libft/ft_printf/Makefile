# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 16:03:13 by lihrig            #+#    #+#              #
#    Updated: 2025/02/20 16:25:36 by lihrig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

PRINTF_SRCS = ft_printf.c \
	ft_myputchar.c \
	ft_putchar_mod.c \
	ft_print_p.c \
	ft_putnbr_mod.c \
	ft_putnbr_unsigned.c \
	ft_print_x.c \
	ft_print_upper_x.c \

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(PRINTF_OBJS)
	ar rcs $(NAME) $(PRINTF_OBJS)

clean:
	rm -f $(PRINTF_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re