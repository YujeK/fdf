# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/15 17:15:14 by asamir-k          #+#    #+#              #
#    Updated: 2018/11/01 19:20:13 by asamir-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf
GCC= GCC
HEADER= INCLUDES/fdf.h
FLAGS = -Wall -Werror -Wextra
LIB_PATH= INCLUDES/libft/
COMP= mlx
MLXLIB= -L mlx -lmlx -framework Opengl -framework Appkit
SRC=SRCS/main.c 			\
	SRCS/linedrawer.c		\
	SRCS/keyboardinputs.c 	\
	SRCS/mouseinputs.c		\
	SRCS/parsing.c 			\
	SRCS/ft_printbucket.c   \
	SRCS/ft_error.c 		\
	SRCS/ft_readverif.c		\
	SRCS/ctword.c			\
	SRCS/rainbow.c			\
	SRCS/ft_isdigit.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c $(HEADER)
	@gcc $(FLAGS) -o $@ -c $< -I $(LIB_PATH) -I ../INCLUDES

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) -lft $(MLXLIB) -I $(COMP)
	@echo "\033[1;34;2m FRIED CHICKEN READY TO BE EATEN ~ (__)=3 ~\033[0m"
	@echo "\033[0;31;3m                        (ALL RULE DONE)                               ~ (__)=3 ~\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[1;33;2m IVE EATEN HALF OF THE CHICKEN , ONE WORD AND WINGS ERADICATION WILL BE ORDERED \033[0m"
	@echo "\033[0;31;3m                        (CLEAN RULE DONE)                             ~ (__)=3 ~ \033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31;2m JOB DONE SERGEANT WingZLord NO MORE WINGS ARE DETECTED IN THE bckt (-_-)ゞ\033[0m"
	@echo "\033[0;31;3m                        (FCLEAN RULE DONE)                            ~ (__)=3  ~\033[0m"

re: fclean all
	@echo "\033[0;35;2m BTW I'VE SUCCESSFULLY REFILL 24 WINGS JUST FOR YOU (♥_♥)ゞ\033[0m"
	@echo "\033[0;31;3m                        (RE RULE DONE)                                ~ (__)=3  ~\033[0m"
