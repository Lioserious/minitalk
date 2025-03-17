CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

# Libft Quellen
MY_SOURCES = ft_isalpha.c \
 ft_isdigit.c \
 ft_isalnum.c \
 ft_isascii.c \
 ft_isprint.c \
 ft_strlen.c \
 ft_memset.c \
 ft_bzero.c \
 ft_memcpy.c \
 ft_memmove.c \
 ft_strlcpy.c \
 ft_strlcat.c \
 ft_toupper.c \
 ft_tolower.c \
 ft_strchr.c \
 ft_strrchr.c \
 ft_strncmp.c \
 ft_memchr.c \
 ft_memcmp.c \
 ft_strnstr.c \
 ft_atoi.c \
 ft_calloc.c \
 ft_strdup.c \
 ft_substr.c \
 ft_strjoin.c \
 ft_strtrim.c \
 ft_split.c \
 ft_itoa.c \
 ft_strmapi.c \
 ft_striteri.c \
 ft_putchar_fd.c \
 ft_putstr_fd.c \
 ft_putendl_fd.c \
 ft_putnbr_fd.c \
 ft_atof.c \

# printf Quellen
PRINTF_DIR = ft_printf
PRINTF_SRCS = ft_printf.c \
 ft_myputchar.c \
 ft_putchar_mod.c \
 ft_print_p.c \
 ft_putnbr_mod.c \
 ft_putnbr_unsigned.c \
 ft_print_x.c \
 ft_print_upper_x.c

# Objekte
MY_OBJECTS = $(MY_SOURCES:%.c=%.o)
PRINTF_OBJS = $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS:.c=.o))
ALL_OBJS = $(MY_OBJECTS) $(PRINTF_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(ALL_OBJS)
	ar rcs $(NAME) $(ALL_OBJS)

all: $(NAME)

clean:
	rm -f $(MY_OBJECTS) $(PRINTF_OBJS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re