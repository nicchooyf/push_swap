# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 10:54:07 by nchoo             #+#    #+#              #
#    Updated: 2022/08/28 10:21:04 by nchoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
BONUS			=	checker
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
MAIN_FILE		=	main.c
SRC_FILES		=	linked_list.c \
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
					bonus_do_check.c \
					bonus_error.c
BONUS_SRC_DIR	=	src/checker
SRC_DIR			=	src/push_swap
MAIN_SRC		=	src/push_swap/main.c
SRC				=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRC		=	$(addprefix $(BONUS_SRC_DIR)/, $(BONUS_SRC_FILES))
RM				=	rm
LIBFT			=	./libft/libft.a
INCLUDES		=	-I includes

all:	$(NAME)

bonus:	$(BONUS)

$(NAME):
			@make -C libft
			@$(CC) $(CFLAGS) $(SRC) $(MAIN_SRC) $(INCLUDES) $(LIBFT) -o $(NAME)

$(BONUS):
			@make -C libft
			@$(CC) $(CFLAGS) $(BONUS_SRC) $(SRC) $(INCLUDES) $(LIBFT) -o $(BONUS)

clean:
			@$(RM) -rf $(OBJ_DIR)

fclean: 	clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(BONUS)
		
re: 		fclean all bonus

.PHONY:		all bonus clean fclean re
