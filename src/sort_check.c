/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:37:20 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/23 19:24:04 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_struct *stack)
{
	t_struct	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_index(t_struct *stack, int half)
{
	t_struct	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->index < half)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}