/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:41:51 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/21 18:18:53 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void swap(t_struct **stack)
// {

// }

void rotate(t_struct **stack)
{
	t_struct *tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	*stack = list_last(*stack);
	(*stack)->next = tmp;
	
}

// void reverse_rotate(t_struct **stack)
// {

// }