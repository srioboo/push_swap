/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/04 16:03:39 by srioboo-         ###   ########.fr       */
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

int	binary_compare(int nb1, int nb2)
{
	int	result;

	result = nb1 & nb2;
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

int	find_max(t_link_list *lst)
{
	int	nb_current;
	int	nb_next;
	int	max;

	nb_current = 0;
	nb_next = 0;
	max = 0;

	while (lst)
	{
		if (lst->content)
			nb_current = lst->content;
		if (lst->next)
			nb_next = lst->next->content;
		if ((nb_current >= nb_next) && (nb_current > max))
			max = nb_current;
		lst = lst->next;
	}
	return (max);
}

int	set_max(int nb1, int nb2)
{
	int	max;

	if (nb1 >= nb2)
		max = nb1;
	else if (nb1 < nb2)
		max = nb2;
	return (max);
}
