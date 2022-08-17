/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:04:33 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/17 20:53:18 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"

typedef struct s_struct
{
	int	value;
	int	index;
	int pos;
	int	target_pos;
	struct s_struct *next;
} 	t_struct;

#endif