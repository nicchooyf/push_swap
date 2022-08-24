/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:55:09 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 00:49:19 by nchoo            ###   ########.fr       */
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
	if (ac == 2)
		return (split_arg(av[1]));
	while (++i < ac)
	{
		if (!check_arg(av[i]))
		{
			free_list(&head);
			return (NULL);
		}
		tmp = new_node(ft_atoi(av[i]));
		add_back(&head, tmp);
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_struct	*stack_a;
	t_struct	*stack_b;
	int			size;

	if (ac < 2)
		return (ft_printf("Too few arguments given\n"));
	stack_a = fill_stack(ac, av);
	stack_b = NULL;
	size = get_size(stack_a);
	stack_a = assign_index(stack_a, size + 1);
	if (!stack_a)
		return (ft_printf("Invalid arguments given\n"));
	do_sort(&stack_a, &stack_b, size);
	// print_result(stack_a, stack_b);
	// system("leaks push_swap");
}