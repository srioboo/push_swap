/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/06 17:06:25 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sort(t_link_list **a, t_link_list **b)
{
	int	list_size;

	list_size = link_lstsize(*a);
	if (list_size < 4)
		tiny_sort(a, list_size);
	else if (list_size == 4 || list_size == 5)
		medium_sort(a, b);
	else
	{
		normalize_list(*a);
		full_sort(a, b);
	}
}

static void	full_sort_b(t_link_list **a, t_link_list **b, int bit_size, int i)
{
	int	b_size;

	b_size = link_lstsize(*b);
	while (b_size-- && i <= bit_size && is_list_sorted(a) == FALSE)
	{
		if ((((*b)->index >> i) & 1) == 0)
			rotate_b(b);
		else
			push_to_a(b, a);
	}
	if (is_list_sorted(a))
		while ((*b))
			push_to_a(b, a);
}

void	full_sort(t_link_list **a, t_link_list **b)
{
	int	i;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = link_lstsize(*a);
	while ((1 << bit_size) < size)
		bit_size++;
	i = -1;
	while (++i < bit_size)
	{
		size = link_lstsize(*a);
		while ((size-- > 0) && is_list_sorted(a) == FALSE)
		{
			if ((((*a)->index >> i) & 1) == 0)
				push_to_b(a, b);
			else
				rotate_a(a);
		}
		full_sort_b(a, b, bit_size, i + 1);
	}
	while ((*b))
		push_to_a(b, a);
}

void	tiny_sort(t_link_list **a, int list_size)
{
	int	max_val;

	update_min_max(*a);
	max_val = (*a)->max_val;
	while (is_list_sorted(a) == 0)
	{
		if (list_size == 2)
			swap_a(a);
		else if ((*a)->content == max_val)
			rotate_a(a);
		else if (((*a)->next->content) == max_val)
		{
			swap_a(a);
			rotate_a(a);
		}
		else if (((*a)->content) > ((*a)->next->content))
			swap_a(a);
	}
}

void	medium_sort(t_link_list **a, t_link_list **b)
{
	int		min_pos;

	while (link_lstsize(*a) > 3)
	{
		update_min_max(*a);
		min_pos = find_min_pos(*a, (*a)->min_val);
		if (min_pos <= link_lstsize(*a) / 2)
			while ((*a)->content != (*a)->min_val)
				rotate_a(a);
		else
			while ((*a)->content != (*a)->min_val)
				rev_rotate_a(a);
		push_to_b(a, b);
	}
	tiny_sort(a, 3);
	while ((*b))
		push_to_a(b, a);
}
