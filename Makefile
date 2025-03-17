# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 16:11:38 by lihrig            #+#    #+#              #
#    Updated: 2025/03/17 16:32:43 by lihrig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler und Flags
CC = cc
CC_FLAGS = -Wall -Werror -Wextra

# Targets
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

# Source und Object Files
SRC_FILES = server.c client.c utils.c parser.c logger.c
SRC_FILES_BONUS = server_bonus.c client_bonus.c utils.c parser.c logger.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)
OBJ_FILES_BONUS = $(SRC_FILES_BONUS:%.c=%.o)

# Libft Pfade
LIBFT_DIR = lib/Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Regel um .c Dateien in .o Dateien zu kompilieren
%.o: %.c
	$(CC) $(CC_FLAGS) -I$(LIBFT_DIR) -c $< -o $@

# Default Target
all: $(LIBFT) $(SERVER) $(CLIENT)

# Regel um die ausführbaren Dateien zu erstellen
$(SERVER): server.o utils.o parser.o logger.o $(LIBFT)
	$(CC) $(CC_FLAGS) server.o utils.o parser.o logger.o -L$(LIBFT_DIR) -lft -o $(SERVER)

$(CLIENT): client.o utils.o parser.o logger.o $(LIBFT)
	$(CC) $(CC_FLAGS) client.o utils.o parser.o logger.o -L$(LIBFT_DIR) -lft -o $(CLIENT)

$(SERVER_BONUS): server_bonus.o utils.o parser.o logger.o $(LIBFT)
	$(CC) $(CC_FLAGS) server_bonus.o utils.o parser.o logger.o -L$(LIBFT_DIR) -lft -o $(SERVER_BONUS)

$(CLIENT_BONUS): client_bonus.o utils.o parser.o logger.o $(LIBFT)
	$(CC) $(CC_FLAGS) client_bonus.o utils.o parser.o logger.o -L$(LIBFT_DIR) -lft -o $(CLIENT_BONUS)

# Libft bauen (falls noch nicht gebaut)
$(LIBFT):
	make -C $(LIBFT_DIR)

# Bonus Anweisungen
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

# Aufräumen von Object Dateien und ausführbaren Dateien
clean:
	rm -f $(OBJ_FILES) $(OBJ_FILES_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	make -C $(LIBFT_DIR) fclean

re: fclean all

# OS-spezifische Konfiguration für Debug
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin) # macOS
	DEBUG_TOOL = lldb
else # Linux und andere
	DEBUG_TOOL = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
endif

# Debug Test
debug: CC_FLAGS += -g
debug: re
	$(DEBUG_TOOL) ./$(SERVER)

# Compiler mit Address Sanitizer
san: CC_FLAGS += -fsanitize=address -g
san: re

.PHONY: all clean fclean re bonus debug san