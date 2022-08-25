/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:59:46 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 23:21:15 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_struct	*stack_a;
	t_struct	*stack_b;
	t_struct	*tmp;
	
	if (ac == 1)
		return (0);
	stack_a = fill_stack_b(ac, av);
	stack_b = NULL;
	stack_a = assign_index_b(stack_a, get_size_b(stack_a));
	if (!stack_a)
		return (write(2, "Error\n", 6));
	// do_check(stacks);

	
	tmp = stack_a;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}