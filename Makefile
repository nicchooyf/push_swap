# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 10:54:07 by nchoo             #+#    #+#              #
#    Updated: 2022/08/25 23:18:23 by nchoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
BONUS			=	checker
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
SRC_FILES		=	main.c \
					linked_list.c \
					free.c \
					operators.c \
					stack_utils.c \
					sort_check.c \
					error.c \
					sort_three.c \
					do_sort.c \
					push.c \
					position.c \
					cost.c
BONUS_SRC_FILES	=	bonus_main.c \
					bonus_error.c \
					bonus_stack_utils.c
BONUS_SRC_DIR	=	src/checker
SRC_DIR			=	src/push_swap
SRC				=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRC		=	$(addprefix $(BONUS_SRC_DIR)/, $(BONUS_SRC_FILES))
OBJ_FILES		=	$(SRC_FILES:%.c=%.o)
BONUS_OBJ_FILES	=	$(BONUS_SRC_FILES:%.c=%.o)
OBJ_DIR			=	obj
OBJ				=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
BONUS_OBJ		=	$(addprefix $(OBJ_DIR)/, $(BONUS_OBJ_FILES))
RM				=	rm
LIBFT			=	./libft/libft.a
INCLUDES		=	-I includes

all:	$(NAME)

bonus:	$(BONUS)

$(NAME):
			@make -C libft
			@$(CC) $(CFLAGS) $(SRC) $(INCLUDES) $(LIBFT) -o $(NAME)

$(BONUS):
			@make -C libft
			@$(CC) $(CFLAGS) $(BONUS_SRC) $(INCLUDES) $(LIBFT) -o $(BONUS)

clean:
			@$(RM) -rf $(OBJ_DIR)

fclean: 	clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(BONUS)
		
re: 		fclean all

.PHONY:		all bonus clean fclean re
