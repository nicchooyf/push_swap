/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:41:51 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/23 21:46:00 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_struct **stack, int c)
{
	t_struct	*tmp;
	t_struct	*next;

	tmp = *stack;
	*stack = (*stack)->next;
	next = (*stack)->next;
	(*stack)->next = tmp;
	tmp->next = next;
	set_position(stack);
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void rotate(t_struct **stack, int c)
{
	t_struct	*tmp;
	t_struct	*tail;

	if (!(*stack))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = list_last(*stack);
	tail->next = tmp;
	tmp->next = NULL;
	set_position(stack);
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}


void reverse_rotate(t_struct **stack, int c)
{
	t_struct	*tmp;
	t_struct	*tail;

	if (!(*stack))
		return	;
	tail = list_last(*stack);
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	tail->next = *stack;
	*stack = tail;
	set_position(stack);
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}
