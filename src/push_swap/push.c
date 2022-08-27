/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:35:24 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/27 17:33:54 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Push function. Changes depending on 'c' input.
 *
 *	If 'pa', resets list members unused in stack a
 */
void	push(t_struct **src, t_struct **des, int c)
{
	t_struct	*tmp;

	tmp = remove_front(src);
	if (c == 'a')
	{
		tmp->target_pos = 0;
		tmp->cost_a = 0;
		tmp->cost_b = 0;
	}
	add_front(des, tmp);
	set_position(src);
	set_position(des);
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}

/*
 *	Pushes everything to 'b' while slightly sorting
 *
 *	If the index is bigger than half of the stack size, rotate before pushing
 *	so that similar indices stay closer to each other. 
 *
 *	When no indices are bigger than half ot he stack size,
 *	pushes all
 */
void	smart_push(t_struct **stack_a, t_struct **stack_b, int size)
{
	t_struct	*tmp;
	int			half;

	half = size / 2;
	while (!check_index(*stack_a, half))
	{
		tmp = *stack_a;
		if (tmp->index > half)
			rotate(stack_a, 'a');
		else
		{
			push(stack_a, stack_b, 'b');
			size--;
		}
	}
	while (size > 3)
	{
		push(stack_a, stack_b, 'b');
		size--;
	}
}

/*
 *	When both cost_a and cost_b are positive, both need to be rotated
 *
 *	Similarly when both cost_a and cost_b are negatie, both need to be
 *	reverse rotated
 */
void	check_both(t_struct *tmp, t_struct **stack_a, t_struct **stack_b)
{
	while (tmp->cost_a > 0 && tmp->cost_b > 0)
	{
		do_rr(stack_a, stack_b, 1);
		tmp->cost_a--;
		tmp->cost_b--;
	}
	while (tmp->cost_a < 0 && tmp->cost_b < 0)
	{
		do_rrr(stack_a, stack_b, 1);
		tmp->cost_a++;
		tmp->cost_b++;
	}
}

/*
 *	Pushes the element with the cheapest absolute cost to 
 *	the top of the stack
 */
void	cheapest_to_top(t_struct **stack, int cost, int c)
{
	while (cost != 0)
	{
		if (cost > 0)
		{
			if (c == 'a')
				rotate(stack, 'a');
			else if (c == 'b')
				rotate(stack, 'b');
			cost--;
		}
		else
		{
			if (c == 'a')
				reverse_rotate(stack, 'a');
			else if (c == 'b')
				reverse_rotate(stack, 'b');
			cost++;
		}
	}
}

/*
 *	Determines the location of the element with the given 'pos'
 *	and pushes that to stack_a
 */
void	push_cheapest(t_struct **stack_a, t_struct **stack_b, int pos)
{
	t_struct	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->pos == pos)
			break ;
		tmp = tmp->next;
	}
	check_both(tmp, stack_a, stack_b);
	cheapest_to_top(stack_a, tmp->cost_a, 'a');
	cheapest_to_top(stack_b, tmp->cost_b, 'b');
	push(stack_b, stack_a, 'a');
}
