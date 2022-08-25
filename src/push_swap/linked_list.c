/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:28:51 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 19:31:04 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Function to create a new linked list element
 *	with the given value
 */
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
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	return (new);
}

/*
 *	Returns the final element of a list
 */
t_struct	*list_last(t_struct *node)
{
	while (node && node->next)
			node = node->next;
	return (node);
}

/*
 *	Adds an element to the back of a list
 */
void	add_back(t_struct **head, t_struct *node)
{
	t_struct	*tmp;

	if (!(*head))
	{
		*head = node;
		return ;
	}
	else
	{
		tmp = list_last(*head);
		tmp->next = node;
	}
}

/*
 *	Adds an element to the front of a list
 */
void	add_front(t_struct **head, t_struct *node)
{
	if (!(*head))
	{
		*head = node;
		return ;
	}
	else
	{
		node->next = *head;
		*head = node;
	}
}

/*
 *	Removes an element from the front of a list
 *
 *	Returns the removed element
 *
 *	Main use is to facilitate the 'push' functions
 */
t_struct	*remove_front(t_struct **head)
{
	t_struct	*tmp;

	tmp = *head;
	*head = tmp->next;
	tmp->next = NULL;
	return (tmp);
}
