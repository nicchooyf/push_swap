/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:55:09 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/21 18:18:06 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*fill_stack(int ac, char **av)
{
	t_struct	*head;
	t_struct	*tmp;
	int 		i;

	i = 0;
	head = NULL;
	while (++i < ac)
	{
		tmp = new_node(ft_atoi(av[i]));
		add_back(&head, tmp);
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_struct	*stack_a;
	t_struct	*stack_b;
	t_struct	*tmp;

	if (ac < 2)
		return (ft_printf("Too few arguments given.\n"));
	stack_a = fill_stack(ac, av);
	stack_b = NULL;
	rotate(&stack_a);
	while (stack_a)
	{
		printf("%d\n", stack_a->value);
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
	// system("leaks push_swap");
}