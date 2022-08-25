/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:23:14 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 19:17:18 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Assigns positions of every element of a stack
 *
 *	Starts from '0' to help with easier cost calculations
 */
void	set_position(t_struct **stack)
{
	t_struct	*tmp;
	int			i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/*
 *	Assigns target positions for when the 'b' index has an 
 *	'a' index bigger than it
 *
 *	Takes the position of the 'a' index immediately bigger than it as its
 *	target position
 */
void	calc_target(t_struct *node, t_struct **stack_a)
{
	t_struct	*tmp;
	int			target_index;

	target_index = INT_MAX;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > node->index && tmp->index < target_index)
		{
			target_index = tmp->index;
			node->target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index == INT_MAX)
		calc_target2(node, stack_a);
}

/*
 *	Assigns target positions for when the 'b' index is 
 *	bigger than all the 'a' indices
 *
 *	Takes the position of the smallest 'a' index, so that it can easily be
 *	rotated to the back of the stack
 */
void	calc_target2(t_struct *node, t_struct **stack_a)
{
	t_struct	*tmp;
	int			target_index;

	target_index = INT_MAX;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < target_index)
		{
			target_index = tmp->index;
			node->target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
}

/*
 *	Assigns a target position to each element of stack_b
 */
void	set_target_pos(t_struct **stack_a, t_struct **stack_b)
{
	t_struct	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		calc_target(tmp, stack_a);
		tmp = tmp->next;
	}
}
