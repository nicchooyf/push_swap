/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:28:26 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 16:57:58 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Calculates the absolute cost of moving an element to the top
 *	of the stack
 */
int	absolute_cost(t_struct *node)
{
	int			cost_a;
	int			cost_b;
	int			cost_total;

	cost_a = node->cost_a;
	cost_b = node->cost_b;
	if (cost_a < 0)
		cost_a *= -1;
	if (cost_b < 0)
		cost_b *= -1;
	cost_total = cost_a + cost_b;
	return (cost_total);
}

/*
 *	Calculates the cost of moving the element in stack_a with
 *	the target_pos of the current stack_b element to the top of stack_a
 */
void	calculate_cost_a(t_struct **stack_a, t_struct *node, int size)
{
	t_struct	*tmp;
	int			half;

	half = size / 2;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->pos == node->target_pos)
			break ;
		tmp = tmp->next;
	}
	node->cost_a = 0;
	if (tmp->pos > half)
		node->cost_a = -(size - tmp->pos);
	else
		node->cost_a = tmp->pos;
}

/*
 *	Calculates the cost of moving the current element in stack_b to the
 *	top of stack_b
 */
void	calculate_cost_b(t_struct *stack_b, int size)
{
	t_struct	*tmp;
	int			half;

	half = size / 2;
	tmp = stack_b;
	tmp->cost_b = 0;
	if (tmp->pos > half)
		tmp->cost_b = -(size - tmp->pos);
	else
		tmp->cost_b = tmp->pos;
}

/*
 *	Assigns a cost of moving an element to the top of the stack
 *
 *	Makes use of the size of the stack to determine whether it is 
 *	more efficient to R or RR. 
 *
 *	If the position is more than half of the stack size, it's at the top = R
 *	If the position is less than half of the stack size, it's at the bottom = RR
 */
void	calculate_cost(t_struct **stack_a, t_struct **stack_b)
{
	t_struct	*tmp;
	t_struct	*node;
	int			size_a;
	int			size_b;

	size_a = get_size(*stack_a);
	size_b = get_size(*stack_b);
	tmp = *stack_b;
	while (tmp)
	{
		node = tmp;
		calculate_cost_a(stack_a, tmp, size_a);
		calculate_cost_b(node, size_b);
		tmp = tmp->next;
	}
}
