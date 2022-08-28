/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_do_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:32:40 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/28 09:29:15 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_operations(int i, int size, t_struct *stack)
{
	if (size == 3 && i == 2 && !is_sorted(stack))
		return (0);
	if (size == 5 && i == 12 && !is_sorted(stack))
		return (0);
	if (size <= 100 && i > 1500)
		return (0);
	if (size <= 500 && i > 11500)
		return (0);
	return (1);
}

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
		if (!check_operations(i, size, *stack_a))
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
