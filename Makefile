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

NAME            = minishell
CC              = gcc
RM              = rm -rf
FLAGS           = -Wall -Wextra -Werror -ILibft -g3 #-fsanitize=address
LREADLINE_FLAGS = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib
READLINE        = -I /Users/$(USER)/.brew/opt/readline/include

# FILES AND PATH
HEADER_SRCS = minishell.h
HEADER_DIR  = includes/
HEADER      = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS  = \
	main.c \
	ft_command_select.c \
	ft_error.c \
	ft_error_ext.c \
	ft_parsing.c \
	ft_split_quote.c \
	ft_split_quote_clear.c \
	ft_pipe.c \
	ft_echo.c \
	ft_getcwd.c \
	ft_cd.c \
	ft_export.c \
	ft_free.c \
	ft_unset.c \
	ft_set_env.c \
	ft_redir.c \
	ft_signal.c \
	ft_pilot.c \
	ft_parsing_utils.c \
	ft_split_quote_utils.c \
	ft_split_quote_clear_utils.c \
	ft_cd_utils.c \
	ft_export_utils.c

MPATH_DIR   = src/
MPATH       = $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M       = $(MPATH:.c=.o)

# COMMANDS
all: lib $(NAME)

$(NAME): $(OBJ_M)
	$(CC) $(FLAGS) $(OBJ_M) libft.a gnl.a $(LREADLINE_FLAGS) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(FLAGS) $(READLINE) -c $< -o $@

clean:
	$(RM) $(OBJ_M)
	$(MAKE) -C Libft clean
	$(MAKE) -C gnl clean

fclean: clean
	$(RM) $(NAME)
	$(RM) libft.a
	$(RM) gnl.a

re: fclean all

lib:
	$(MAKE) -C Libft
	cp Libft/libft.a .
	$(MAKE) -C gnl
	cp gnl/gnl.a .

.PHONY: all clean fclean re lib
