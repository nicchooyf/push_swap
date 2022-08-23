# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 10:54:07 by nchoo             #+#    #+#              #
#    Updated: 2022/08/23 21:31:18 by nchoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
SRC_FILES		=	main.c \
					linkedlist.c \
					free.c \
					operators.c \
					stack_utils.c \
					sort_check.c \
					error.c \
					sort_three.c \
					push.c \
					position.c \
					test.c
SRC_DIR			=	src
SRC				=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_FILES		=	$(SRC_FILES:%.c=%.o)
OBJ_DIR			=	obj
OBJ				=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
RM				=	rm
LIBFT			=	libft/libft.a
INCLUDES		=	-I includes

all:	$(NAME)

$(NAME):
			@make -C libft
			@$(CC) $(CFLAGS) $(SRC) $(INCLUDES) $(LIBFT) -o $(NAME)

clean:
			@$(RM) -rf $(OBJ_DIR)

fclean: 	clean
			@$(RM) -f $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
