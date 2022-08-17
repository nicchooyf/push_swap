/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:55:09 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/17 23:17:19 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(int ac, char **av)
{
	t_struct	*tmp;
	int 		i;

	i = 1;
	while (i < ac)
	{
		tmp = new_node(ft_atoi(av[i]);
		add_back(&stack, tmp);
	}
}

int	main(int ac, char **av)
{
	t_struct	*stack_a;

	if (ac < 2)
		return (ft_printf("Too few arguments given.\n"));
	stack_a = fill_stack(ac, av);
	while (stack_a)
	{
		printf("%d", stack_a->value);
		stack_a = stack_a->next;
	}
}