# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/07 15:05:07 by asamir-k          #+#    #+#              #
#    Updated: 2018/10/06 17:30:46 by asamir-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a
GCC= GCC
HEADER= libft.h
FLAGS= -Wall -Werror -Wextra
AR:= ar rc
RL= ranlib
SRC= get_next_line.c \
	ft_putchar.c \
	ft_atoi.c \
	ft_isascii.c \
	ft_strchr.c \
	ft_strjoinfree.c \
	ft_strdup.c \
	ft_strsubfree.c \
	ft_strncat.c \
	ft_strnstr.c \
	ft_tolower.c \
	ft_isalnum.c \
	ft_isdigit.c \
	ft_putstr.c \
	ft_strcmp.c \
	ft_strlcat.c \
	ft_strncmp.c \
	ft_strrchr.c \
	ft_toupper.c \
	ft_isalpha.c \
	ft_isprint.c \
	ft_strcat.c \
	ft_strcpy.c \
	ft_strlen.c \
	ft_strncpy.c \
	ft_strstr.c \
	ft_memcpy.c \
	ft_memcmp.c \
	ft_putnbr.c \
	ft_putendl.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strnew.c \
	ft_memset.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strnequ.c \
	ft_memalloc.c \
	ft_memmove.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsub.c \
	ft_bzero.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memdel.c \
	ft_strequ.c \
	ft_strmapi.c \
	ft_strsplit.c \
	ft_lenint.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_iswhite.c \
	ft_swap.c \
	ft_print_words_tables.c \
	ft_range.c \
ft_itoa.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c $(HEADER)
	@gcc $(FLAGS) -o $@ -c $< -I libft.h

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32;1;4mYoyoyoyoyoyoyo\033[0m"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	make
