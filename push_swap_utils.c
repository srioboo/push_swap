/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/08 09:38:42 by srioboo-         ###   ########.fr       */
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

void	show_op_msg(char *op)
{
	int	len;

	if (op != NULL)
	{
		len = ft_strlen(op);
		write(1, op, len);
		write(1, "\n", 1);
	}
}

int	show_error_msg(void)
{
	write(1, "Error\n", 7);
	return (0);
}

int	set_max(int nb1, int nb2)
{
	if (nb1 >= nb2)
		return (nb1);
	return (nb2);
}

int	set_min(int nb1, int nb2)
{
	if (nb1 <= nb2)
		return (nb1);
	return (nb2);
}