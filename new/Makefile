# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 14:48:24 by tfedoren          #+#    #+#              #
#    Updated: 2022/08/25 12:52:51 by tfedoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT_PATH	=	Libft

SRC =	main.c \
		double_quotes.c \
		single_quotes.c \
		quotes_utils.c \
		splitting_by_pipes.c \
		parsing.c \
		helper_functions.c \
		splitting_by_spaces.c \
		removing_qoutes.c \
		lexer.c \
		lexer_helpers_lists.c


OBJ = $(SRC:.c=.o)


CC = gcc
CFLAGS = #-Wall -Wextra -Werror -g
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME) -g -I $(HOME)/goinfre/.brew/opt/readline/include/ -L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline


clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all
	make -C $(LIBFT_PATH) re

.PHONY: all clean fclean re bonus

#gcc main.c -Lmlx -lmlx -framework OpenGL -framework AppKit