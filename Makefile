# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 12:17:20 by iportill          #+#    #+#              #
#    Updated: 2023/11/28 16:11:00 by jgoikoet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
RM = rm -f
LREADLINE_FLAGS = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib
READLINE = -I /Users/$(USER)/.brew/opt/readline/include
LIB = libft.a
GNL = gnl.a
BONUS = minishell_bonus
SRC_DIR = src/
SRC =	$(SRC_DIR)main.c \
		$(SRC_DIR)ft_command_select.c \
		$(SRC_DIR)ft_error.c \
		$(SRC_DIR)ft_error_ext.c \
		$(SRC_DIR)ft_parsing.c \
		$(SRC_DIR)ft_split_quote.c \
		$(SRC_DIR)ft_split_quote_clear.c \
		$(SRC_DIR)ft_pipe.c \
		$(SRC_DIR)ft_echo.c \
		$(SRC_DIR)ft_getcwd.c \
		$(SRC_DIR)ft_cd.c \
		$(SRC_DIR)ft_export.c \
		$(SRC_DIR)ft_free.c \
		$(SRC_DIR)ft_unset.c \
		$(SRC_DIR)ft_set_env.c \
		$(SRC_DIR)ft_redir.c \
		$(SRC_DIR)ft_signal.c \
		$(SRC_DIR)ft_pilot.c \
		$(SRC_DIR)ft_parsing_utils.c \
		$(SRC_DIR)ft_split_quote_utils.c \
		$(SRC_DIR)ft_split_quote_clear_utils.c \
		$(SRC_DIR)ft_cd_utils.c \
		$(SRC_DIR)ft_export_utils.c


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

define MINISHELL
$(GREEN)
 +-+-+-+-+-+-+-+-+-+
 |M|I|N|I|T|X|E|L|L|
 +-+-+-+-+-+-+-+-+-+                                                         
$(END)
endef
export MINISHELL

#.SILENT:             #<--------------SILENCED COMPILATION
all: $(NAME) $(LIB) $(GNL)

$(NAME): $(OBJ) $(GNL) $(LIB)
	$(CC) $(CFLAGS) $(LIB) $(GNL) $(LREADLINE_FLAGS) -o $(NAME) $(OBJ)
	echo "$$MINISHELL"

$(LIB):
	make -C Libft
	cp Libft/$(LIB) $(LIB)

$(GNL):
	make -C gnl
	cp gnl/$(GNL) $(GNL)

bonus:
	make -C bonus
	cp bonus/$(BONUS) $(BONUS)

%.o: %.c
	$(CC) $(READLINE) -c $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)
	make -C gnl clean
	make -C Libft clean
	make -C bonus clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(GNL)
	$(RM) $(LIB)
	$(RM) $(BONUS)
	make -C gnl fclean
	make -C Libft fclean
	make -C bonus fclean

#lib:
#	make -C Libft
#	cp Libft/$(LIB) $(LIB)
#	make -C gnl
#	cp gnl/$(GNL) $(GNL)

re: fclean all

.PHONY: all clean fclean re lib bonus