/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:55:09 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/27 18:13:15 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_struct	*stack_a;
	t_struct	*stack_b;
	int			size;

	if (ac < 2)
		return (write(2, "Error\n", 6));
	stack_a = fill_stack(ac, av);
	stack_b = NULL;
	size = get_size(stack_a);
	stack_a = assign_index(stack_a, size + 1);
	if (!stack_a)
		return (write(2, "Error\n", 6));
	do_sort(&stack_a, &stack_b, size);
	free_list(stack_a);
	// system("leaks push_swap");
}
