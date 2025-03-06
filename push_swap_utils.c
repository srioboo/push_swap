/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/07 10:48:40 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_utils_show_op_msg(char *op)
{
	int	len;

	len = ft_strlen(op);
	write(1, op, len);
	write(1, "\n", 1);
}

int	ft_utils_show_error_msg(void)
{
	write(1, "Error\n", 7);
	return (0);
}
