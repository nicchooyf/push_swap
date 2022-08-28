/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:44:26 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/28 09:49:14 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Exits the program and prints "Error"
 *	in the stderr
 */
void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

/*
 *	Checks for INT_MIN <= arg <= INT_MAX
 */
int	check_num(char *arg)
{
	long long int	nbr;

	nbr = ft_atoi(arg);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	else
		return (1);
}

/*
 *	Checks each argument for invalid inputs
 *
 *	Not allowed: 01, -, abc	
 */
int	check_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i + 1] == '\0')
			return (0);
		i++;
	}
	if (!arg[i])
		return (0);
	if (arg[i] == '0' && arg[i + 1] != '\0')
		return (0);
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return (0);
	}
	return (check_num(arg));
}
