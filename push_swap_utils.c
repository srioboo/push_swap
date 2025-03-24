/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/24 13:03:20 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO - implement
int	to_binary(int nb)
{
	int	result;

	result = 0;
	while (nb > 0)
		result /= 2;

	return (result);
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
