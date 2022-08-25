/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 23:03:34 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 23:21:02 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_b(t_struct *stack)
{
	t_struct	*tmp;
	int			size;

	if (!stack)
		return (0);
	size = 1;
	tmp = stack;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

t_struct	*list_last_b(t_struct *node)
{
	while (node && node->next)
			node = node->next;
	return (node);
}

void	add_back_b(t_struct **head, t_struct *node)
{
	t_struct	*tmp;

	if (!(*head))
	{
		*head = node;
		return ;
	}
	else
	{
		tmp = list_last_b(*head);
		tmp->next = node;
	}
}

t_struct	*new_node_b(int value)
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

void	free_list_b(t_struct *head)
{
	t_struct	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	head = NULL;
}

t_struct	*fill_stack_b(int ac, char **av)
{
	t_struct	*head;
	t_struct	*tmp;
	int			i;

	i = 0;
	head = NULL;
	while (++i < ac)
	{
		if (check_arg_b(av[i]) != 1)
		{
			free_list_b(head);
			return (NULL);
		}
		tmp = new_node_b(ft_atoi(av[i]));
		add_back_b(&head, tmp);
	}
	return (head);
}

t_struct	*assign_index_b(t_struct *stack, int index)
{
	t_struct		*head;
	t_struct		*max;
	long long int	max_int;

	head = stack;
	while (--index > 0)
	{
		max_int = LLONG_MIN;
		stack = head;
		while (stack)
		{
			if (stack->value == max_int && !(stack->index))
				return (NULL);
			if (stack->value > max_int && !(stack->index))
			{
				max_int = stack->value;
				max = stack;
			}
			stack = stack->next;
		}
		if (!(max->index))
			max->index = index;
	}
	return (head);
}