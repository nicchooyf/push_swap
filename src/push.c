/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:35:24 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 00:20:11 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Push function. Changes depending on 'c' input.
 *
 *	If 'pa', resets list members unused in stack a
 */
void push(t_struct **src, t_struct **des, int c)
{
	t_struct	*tmp;
	
	tmp =	remove_front(src);
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
void smart_push(t_struct **stack_a, t_struct **stack_b, int	size)
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

void	push_cheapest(t_struct **stack_a, t_struct **stack_b, int pos)
{
	t_struct	*tmp;
	int	cost_a;
	int	cost_b;
	
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->pos == pos)
			break ;
		tmp = tmp->next;
	}
	cost_a = tmp->cost_a;
	cost_b = tmp->cost_b;
	while (cost_a != 0)
	{
		if (cost_a > 0)
		{
			rotate(stack_a, 'a');
			cost_a--;
		}
		else
		{ 
			reverse_rotate(stack_a, 'a');
			cost_a++;
		}
	}
	while (cost_b != 0)
	{
		if (cost_b > 0)
		{
			rotate(stack_b, 'b');
			cost_b--;
		}
		else
		{ 
			reverse_rotate(stack_b, 'b');
			cost_b++;
		}		
	}
	push(stack_b, stack_a, 'a');
}