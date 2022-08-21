/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:04:33 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/21 18:14:12 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"

typedef struct s_struct
{
	int				value;
	int				index;
	int 			pos;
	int				target_pos;
	struct s_struct *next;
} 	t_struct;

t_struct	*new_node(int value);
t_struct	*list_last(t_struct *node);
void		add_back(t_struct **head, t_struct *node);

void	free_list(t_struct **list);

void rotate(t_struct **stack);

#endif