/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:56:58 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/23 20:17:34 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_struct **stack)
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
		else if (tmp->next->index > tmp->index && tmp->next->index > tail->index)
		{
			reverse_rotate(stack, 'a');
			tmp = *stack;
		}
		if (tmp->index > tmp->next->index)
			swap(stack, 'a');
	}
}