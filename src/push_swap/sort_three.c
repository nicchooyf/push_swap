/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:56:58 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 19:02:07 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Function to sort for a stack of size 3
 *
 *	1 3 2
 *		RRA (2 1 3) -> SA (1 2 3)
 *	2 1 3
 *		SA (1 2 3)
 *	2 3 1
 *		RRA (1 2 3)
 *	3 1 2
 *		RA (1 2 3)
 *	3 2 1
 *		RA (2 1 3) -> SA (1 2 3)
 */
void	sort_three(t_struct **stack)
{
	t_struct	*tmp;
	t_struct	*tail;

	tail = list_last(*stack);
	while (!(is_sorted(*stack)))
	{
		tmp = *stack;
		if (tmp->index > tmp->next->index && tmp->index > tail->index)
		{
			rotate(stack, 'a');
			tmp = *stack;
		}
		else if (tmp->next->index > tmp->index
			&& tmp->next->index > tail->index)
		{
			reverse_rotate(stack, 'a');
			tmp = *stack;
		}
		if (tmp->index > tmp->next->index)
			swap(stack, 'a');
	}
}
