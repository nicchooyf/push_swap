/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:23:14 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/23 22:38:34 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_struct **stack)
{
	t_struct	*tmp;
	int			i;

	i = 1;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	calc_target_pos(t_struct *node, t_struct **stack_a)
{
	t_struct	*tmp;
	
	tmp = *stack_a;
	while (tmp)
	{
		if (node->index > tmp->index && node->index < tmp->next->index)
		{
			node->target_pos = tmp->pos + 1;
			return ;
		}
		tmp = tmp->next;
	}
	node->target_pos = 1;
}

void	set_target_pos(t_struct **stack_a, t_struct **stack_b)
{
	t_struct	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		calc_target_pos(tmp, stack_a);
		tmp = tmp->next;
	}
}