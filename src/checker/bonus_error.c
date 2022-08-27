/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:34:43 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/27 17:29:01 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_ok(void)
{
	ft_printf("OK\n");
	exit(0);
}

void	exit_ko(void)
{
	ft_printf("KO\n");
	exit(0);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
