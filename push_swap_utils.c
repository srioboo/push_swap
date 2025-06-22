/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/21 11:57:56 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_intlen(int i)
{
	unsigned int	n_aux;
	int				j;

	j = 0;
	n_aux = i;
	if (i <= 0)
	{
		n_aux = -i;
		j = 1;
	}
	while (n_aux > 0)
	{
		n_aux /= 10;
		j++;
	}
	return (j);
}

int	set_max(int nb1, int nb2)
{
	if (nb1 >= nb2)
		return (nb1);
	return (nb2);
}

int	set_min(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

long	ft_atol(const char *cton)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (cton[i] == ' ' || (cton[i] >= 9 && cton[i] <= 13))
		i++;
	if (cton[i] == '-' || cton[i] == '+')
	{
		if (cton[i] == '-')
			sign *= -1;
		i++;
	}
	while (cton[i] >= '0' && cton[i] <= '9')
	{
		result = result * 10 + (cton[i] - '0');
		i++;
	}
	return (sign * result);
}

int	ft_arrsize(char **arr)
{
	int	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}
