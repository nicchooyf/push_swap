/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:31:55 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 00:29:37 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *
 */
int		find_cheapest(t_struct	**stack_b)
{
	t_struct	*tmp;
	int			pos;
	int			min;
	int			cost_total;
	
	tmp = *stack_b;
	min = INT_MAX;
	while (tmp)
	{
		cost_total = absolute_cost(tmp);
		if (cost_total < min)
		{
			min = cost_total;
			pos = tmp->pos;
			// printf("min:%d pos:%d\n", min, pos);
		}
		tmp = tmp->next;
	}
	// printf("total:%d\n", cost_total);
	return (pos);
}

/*
 *
 */
void	sort_big(t_struct **stack_a, t_struct **stack_b, int size)
{
	t_struct	*tmp;
	int			pos;
	
	smart_push(stack_a, stack_b, size);
	sort_three(stack_a);
	while (*stack_b)
	{
		set_target_pos(stack_a, stack_b);
		calculate_cost(stack_a, stack_b);
		pos = find_cheapest(stack_b);
		// printf("pos:%d\n", pos);
		// print_no_free(*stack_a, *stack_b);
		push_cheapest(stack_a, stack_b, pos);
		// print_no_free(*stack_a, *stack_b);
		// sleep(1);
	}
	if (!(is_sorted(*stack_a)))
	{
		tmp = *stack_a;
		if (tmp->index > size / 2)
		{
			while (!(is_sorted(*stack_a)))
				rotate(stack_a, 'a');
		}
		else
		{
			while (!(is_sorted(*stack_a)))
				reverse_rotate(stack_a, 'a');
		}	
	}
}

/*
 *
 */
void do_sort(t_struct **stack_a, t_struct **stack_b, int size)
{
	if (!is_sorted(*stack_a))
	{
		if (size == 2)
			rotate(stack_a, 'a');
		else if (size == 3)
			sort_three(stack_a);
		else
			sort_big(stack_a, stack_b, size);
	}
	ft_printf("-Sorted!-\n");
}