# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 12:17:20 by iportill          #+#    #+#              #
#    Updated: 2023/10/20 11:34:42 by jgoikoet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
RM = rm -f
# READLINE #
LREADLINE_FLAGS = -lreadline #-L/Users/$(USER)/.brew/opt/readline/lib/
READLINE = -I /Users/$(USER)/.brew/opt/readline/include/
#LINUX_READLINE = -lreadline -L/usr/lib/x86_64-linux-gnu/
LIB = libft.a
SRC_DIR = src/
SRC =	$(SRC_DIR)main.c \
		$(SRC_DIR)ft_error.c \
		$(SRC_DIR)ft_parsing.c \
		$(SRC_DIR)ft_split_quote.c \
		$(SRC_DIR)ft_pipe.c \
		$(SRC_DIR)ft_echo.c \
		$(SRC_DIR)ft_dollar.c
		
OBJ = $(SRC:.c=.o)

# ASCII COLORS #
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
PAPYRUS=\033[38;5;223m
END=\033[0m


# MAKEFILE ART #
#define MINISHELL
#$(RED)

#███╗   ███╗██╗███╗   ██╗██╗██╗  ██╗███████╗██╗     ██╗     
#████╗ ████║██║████╗  ██║██║██║  ██║██╔════╝██║     ██║     
#██╔████╔██║██║██╔██╗ ██║██║███████║█████╗  ██║     ██║     
#██║╚██╔╝██║██║██║╚██╗██║██║██╔══██║██╔══╝  ██║     ██║     
#██║ ╚═╝ ██║██║██║ ╚████║██║██║  ██║███████╗███████╗███████╗
#╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝
                                                           
#$(END)
#endef
#export MINISHELL

define MINISHELL
$(GREEN)
 +-+-+-+-+-+-+-+-+-+
 |M|I|N|I|T|X|E|L|L|
 +-+-+-+-+-+-+-+-+-+                                                         
$(END)
endef
export MINISHELL

.SILENT:             #<--------------SILENCED COMPILATION
all: lib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIB) $(LREADLINE_FLAGS) $(READLINE) -o $(NAME) $(OBJ)
	echo "$$MINISHELL"

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

lib:
	make -C Libft
	cp Libft/$(LIB) $(LIB)

re: fclean all

.PHONY: all clean fclean re