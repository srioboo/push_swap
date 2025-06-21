/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_msg_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/21 11:43:54 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(2, "Error\n", 6);
	return (EXIT_FAILURE);
}
