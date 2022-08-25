/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_do_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:32:40 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 22:59:40 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void do_operation(t_checker *stacks, char *s)
{
	int len;

	len = ft_strlen(s) - 1;
	if (ft_strncmp(s, "sa", len) == 0)
		swap(&(stacks->stack_a), 'a');
		
}

void do_check(t_checker *stacks)
{
	char *op;

	op = get_next_line(0);
	while (op)
	{
		do_operation(stacks, op);
		op = get_next_line(0);
	}
}