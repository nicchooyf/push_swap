/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:28:51 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/17 23:16:09 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*new_node(int value)
{
	t_struct	*new;

	new = malloc(sizeof(t_struct));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = 0;
	new->target_pos = 0;
	new->next = NULL;
	return (new);
}

t_struct	*list_last(t_struct *node)
{
	while (node)
	{
		if (node->next)
			node = node->next;
	}
	return (node);
}

void	add_back(t_struct **stack, t_struct *node)
{
	t_struct *tmp;

	if (!(*stack))
	{
		*stack = node;
		return ;
	}
	else
	{
		tmp = list_last(*stack);
		tmp->next = node;
	}
}