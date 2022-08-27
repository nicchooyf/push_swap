/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_do_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:32:40 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/27 17:28:31 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_operation(t_struct **stack_a, t_struct **stack_b, char *s)
{
	if (ft_strncmp(s, "sa", ft_strlen(s) - 1) == 0)
		swap(stack_a, 0);
	else if (ft_strncmp(s, "sb", ft_strlen(s) - 1) == 0)
		swap(stack_b, 0);
	else if (ft_strncmp(s, "ra", ft_strlen(s) - 1) == 0)
		rotate(stack_a, 0);
	else if (ft_strncmp(s, "rb", ft_strlen(s) - 1) == 0)
		rotate(stack_b, 0);
	else if (ft_strncmp(s, "rr", ft_strlen(s) - 1) == 0)
		do_rr(stack_a, stack_b, 0);
	else if (ft_strncmp(s, "rra", ft_strlen(s) - 1) == 0)
		reverse_rotate(stack_a, 0);
	else if (ft_strncmp(s, "rrb", ft_strlen(s) - 1) == 0)
		reverse_rotate(stack_b, 0);
	else if (ft_strncmp(s, "rrr", ft_strlen(s) - 1) == 0)
		do_rrr(stack_a, stack_b, 0);
	else if (ft_strncmp(s, "pa", ft_strlen(s) - 1) == 0)
		push(stack_b, stack_a, 0);
	else if (ft_strncmp(s, "pb", ft_strlen(s) - 1) == 0)
		push(stack_a, stack_b, 0);
	else
		exit_error();
}

void	do_check(t_struct **stack_a, t_struct **stack_b)
{
	char	*op;
	int		size;
	int		i;

	i = 0;
	size = get_size(*stack_a);
	op = get_next_line(0);
	while (op)
	{
		do_operation(stack_a, stack_b, op);
		i++;
		if (is_sorted(*stack_a) && !*stack_b)
			exit_ok();
		if ((size == 3 && i == 2 && !is_sorted(*stack_a))
			|| (size == 5 && i == 12 && !is_sorted(*stack_a)))
			exit_ko();
		if (ft_strncmp(op, "\n", 1) == 0)
		{
			free(op);
			return ;
		}
		free(op);
		op = get_next_line(0);
	}
}
