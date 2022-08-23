/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:01:37 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/23 18:49:25 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_struct *stack)
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

/*
 *	Assigns (sorted) index to members of the stack
 *
 *	Also checks for duplicates whilst
 */
t_struct	*assign_index(t_struct *stack, int index)
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

t_struct	*split_arg(char *s)
{
	t_struct	*head;
	t_struct	*tmp;
	char		**arg;
	int			i;

	i = 0;
	head = NULL;
	arg = ft_split(s, ' ');
	while (arg[i])
	{
		if (!check_arg(arg[i]))
		{
			free_list(&head);
			return (NULL);
		}
		tmp = new_node(ft_atoi(arg[i]));
		add_back(&head, tmp);
		i++;
	}
	return (head);
}
