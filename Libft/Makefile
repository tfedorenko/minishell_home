# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 16:10:19 by tfedoren          #+#    #+#              #
#    Updated: 2022/05/20 11:28:00 by tfedoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_strnstr.c \
		ft_isdigit.c \
		ft_putstr_fd.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_memcmp.c \
		ft_putnbr_fd.c \
		ft_strchr.c \
		ft_striteri.c \
		ft_bzero.c \
		ft_strjoin.c \
		ft_isascii.c \
		ft_memcpy.c \
		ft_isprint.c \
		ft_putendl_fd.c \
		ft_toupper.c \
		ft_split.c \
		ft_strrchr.c \
		ft_isalpha.c \
		ft_memchr.c \
		ft_putchar_fd.c \
		ft_memset.c \
		ft_substr.c \
		ft_strncmp.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_atoi.c \
		ft_isalnum.c \
		ft_itoa.c \
		ft_tolower.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putvoidptr.c \
		ft_putnbr.c \
		ft_putunsignednbr.c \
		ft_puthexadecimalnbr.c

OBJ = $(SRC:.c=.o)

BONUS =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

BONUS_OBJ =$(BONUS:.c=.o)

HEADER = libft.h

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

bonus: $(BONUS_OBJ) $(HEADER)
	 ar rcs $(NAME) $(BONUS_OBJ)

re: fclean all

.PHONY: all clean fclean re bonus