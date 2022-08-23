/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:35:24 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/23 22:33:11 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_struct **src, t_struct **des, int c)
{
	t_struct	*tmp;
	
	tmp =	remove_front(src);
	if (c == 'a')
		tmp->target_pos = 0;
	add_front(des, tmp);
	set_position(src);
	set_position(des);
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}

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
		// print_no_free(*stack_a, *stack_b);
		// sleep(1);
	}
	while (size > 3)
	{
		push(stack_a, stack_b, 'b');
		size--;
		// print_no_free(*stack_a, *stack_b);
		// sleep(1);
	}
}