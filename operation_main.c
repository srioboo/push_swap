/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/14 15:52:50 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_max_bits(int max_val)
{
	int	max_bits;

	max_bits = 0;
	while ((max_val >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	op_sort(t_link_list **list_a, t_link_list **list_b)
{
	int	list_size;

	list_size = link_lstsize(*list_a);
	if (list_size < 4)
		tiny_sort(list_a, list_size);
	else if (list_size == 4)
		medium_sort(list_a, list_b);
	else if (list_size == 5)
		medium_sort(list_a, list_b);
	else
		full_sort(list_a, list_b);
}

void	full_sort(t_link_list **list_a, t_link_list **list_b)
{
	int	i;
	int	max_bits;
	int	size;
	int	j;

	i = 0;
	max_bits = calculate_max_bits((*list_a)->max_val);
	while (i < max_bits)
	{
		size = link_lstsize(*list_a);
		j = 0;
		while (j < size)
		{
			if ((((*list_a)->content >> i) & 1) == 0)
				push_to_b(list_a, list_b);
			else
				rotate_a(list_a);
			j++;
		}
		while (*list_b)
			push_to_a(list_b, list_a);
		i++;
	}
}

void	tiny_sort(t_link_list **list_a, int list_size)
{
	int	max_val;

	max_val = (*list_a)->max_val;
	if (((*list_a)->content == max_val) && list_size == 3)
		rotate_a(list_a);
	if (((*list_a)->next->content == max_val) && list_size == 3)
		rev_rotate_a(list_a);
	if (((*list_a)->content > (*list_a)->next->content))
		swap_a(list_a);
}

void	medium_sort(t_link_list **list_a, t_link_list **list_b)
{
	int	base;
	int	size;
	int	rep;

	base = 3;
	size = link_lstsize(*list_a);
	rep = (size - base);
	while (rep > 0)
	{
		while ((*list_a)->content != (*list_a)->min_val)
			rotate_a(list_a);
		push_to_b(list_a, list_b);
		rep--;
	}
	tiny_sort(list_a, base);
	rep = (size - base);
	while (rep > 0)
	{
		push_to_a(list_b, list_a);
		rep--;
	}
}
