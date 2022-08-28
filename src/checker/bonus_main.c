/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:59:46 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/28 16:44:13 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_struct	*stack_a;
	t_struct	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = fill_stack(ac, av);
	stack_b = NULL;
	stack_a = assign_index(stack_a, get_size(stack_a) + 1);
	if (!stack_a)
		exit_error();
	do_check(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		exit_ok();
	else
		exit_ko();
}
