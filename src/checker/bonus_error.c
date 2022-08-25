/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 23:07:29 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 23:08:48 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num_b(char *arg)
{
	long long int	nbr;

	nbr = ft_atoi(arg);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	else
		return (1);
}


int	check_arg_b(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i + 1] == '\0')
			return (0);
		i++;
	}
	if (arg[i] == '0' && arg[i + 1] != '\0')
		return (0);
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return (0);
	}
	return (check_num_b(arg));
}