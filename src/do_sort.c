/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:31:55 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 17:04:22 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Rotates the sorted stack until the smallest index is on 
 *	top of the stack
 *
 *	RA if the top index is bigger than half of the stack size
 *	RRA if not
 */
void	final_rotate(t_struct **stack_a, int half)
{
	t_struct	*tmp;

	if (!(is_sorted(*stack_a)))
	{
		tmp = *stack_a;
		if (tmp->index > half)
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
 *	Returns the position of the cheapest element to move,
 *	calculated by summing up the absolute value of 
 *	cost_a and cost_b
 */
int	find_cheapest(t_struct	**stack_b)
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
		}
		tmp = tmp->next;
	}
	return (pos);
}

/*
 *	Function to sort stack sizes of greater than 3
 *
 *	Loop goes:
 *		- Push all elements to stack_b save 3
 *		- Sort the 3 elements remaining in stack_a
 *			- Calculate positions of every element in their stacks
 *			- Assign target positions to every elemeent in stack_b
 *			- Calculate and find the element with the cheapest 
 *			  cost to move
 *			- Move said element
 *			- Repeat until stack_b is empty
 *		- Rotate stack_a until the lowest index is on top
 */
void	sort_big(t_struct **stack_a, t_struct **stack_b, int size)
{
	int			pos;

	smart_push(stack_a, stack_b, size);
	sort_three(stack_a);
	while (*stack_b)
	{
		set_target_pos(stack_a, stack_b);
		calculate_cost(stack_a, stack_b);
		pos = find_cheapest(stack_b);
		push_cheapest(stack_a, stack_b, pos);
	}
	final_rotate(stack_a, size / 2);
}

/*
 *	Chooses which sorting method to use based on the stack size
 */
void	do_sort(t_struct **stack_a, t_struct **stack_b, int size)
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
}
