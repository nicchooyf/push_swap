/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:41:51 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/28 16:55:39 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Swaps the first two indicies of a given stack
 */
void	swap(t_struct **stack, int c)
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

/*
 *	Rotates a given stack, pushing the top element to
 *	the back of the stack
 */
void	rotate(t_struct **stack, int c)
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

/*
 *	Reverse rotates a given stack, pushing the last element
 *	to the front of the stack
 */
void	reverse_rotate(t_struct **stack, int c)
{
	t_struct	*tmp;
	t_struct	*tail;

	if (!(*stack))
		return ;
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

/*
 *	Turns RA and RB to RR
 */
void	do_rr(t_struct **stack_a, t_struct **stack_b, int n)
{
	if ((get_size(*stack_a) < 2) || (get_size(*stack_b) < 2))
		return ;
	rotate(stack_a, 'c');
	rotate(stack_b, 'c');
	if (n == 1)
		ft_printf("rr\n");
}

/*
 *	Turns RRA and RRB to RRR
 */
void	do_rrr(t_struct **stack_a, t_struct **stack_b, int n)
{
	if ((get_size(*stack_a) < 2) || (get_size(*stack_b) < 2))
		return ;
	reverse_rotate(stack_a, 'c');
	reverse_rotate(stack_b, 'c');
	if (n == 1)
		ft_printf("rrr\n");
}
