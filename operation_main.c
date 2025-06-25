/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/25 22:40:10 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_max_bits(int max_val, int min_val)
{
	unsigned int	max_xor;
	unsigned int	min_xor;
	unsigned int	range;
	int				bits;

	bits = 0;
	max_xor = ((unsigned int)max_val) ^ 0x80000000;
	min_xor = ((unsigned int)min_val) ^ 0x80000000;
	if (max_xor > min_xor)
		range = max_xor - min_xor;
	else
		range = min_xor - max_xor;
	while (range >> bits)
		bits++;
	if (bits == 0)
		return (1);
	else if (bits < 32)
		bits = 32;
	return (bits);
}

int	is_list_sorted(t_link_list **ls)
{
	t_link_list	*lst;

	lst = *ls;
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	op_sort(t_link_list **a, t_link_list **b)
{
	int	list_size;

	list_size = link_lstsize(*a);
	if (list_size < 4)
		tiny_sort(a, list_size);
	else if (list_size == 4 || list_size == 5)
		medium_sort(a, b);
	else
		full_sort(a, b);
}

// static void	radix_sort_stack_b(t_link_list **a, t_link_list **b, int b_size, int bit_size, int j)
// {
// 	while (b_size-- && j <= bit_size && !is_list_sorted(a))
// 	{
// 		if ((((*b)->content >> j) & 1) == 0)
// 			rev_rotate_b(b); 
// 		else
// 			push_to_b(b, a);
// 	}
// 	if (is_list_sorted(a))
// 		while (*b)
// 			push_to_b(b, a);
// }

void	full_sort(t_link_list **a, t_link_list **b)
{
	unsigned int	binary_content;
	int				i;
	int				bit_size;
	int				size;

	bit_size = calculate_max_bits((*a)->max_val, (*a)->min_val);
	i = -1;
	while (++i < bit_size)
	{
		size = link_lstsize(*a);
		while (size--) // && !is_list_sorted(a))
		{
			binary_content = (((unsigned int)(*a)->content) ^ 0x80000000);
			if (((binary_content >> i) & 1) == 0)
				push_to_b(a, b);
			else
				rotate_a(a);
		}
		while (*b)
			push_to_a(b, a);

	}

}

void	tiny_sort(t_link_list **a, int list_size)
{
	int	max_val;

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
	int	rep;

	rep = 2;
	while (rep-- > 0)
	{
		if (link_lstlast(*a)->content == (*a)->min_val)
			rev_rotate_a(a);
		while ((*a)->content != (*a)->min_val)
			rotate_a(a);
		push_to_b(a, b);
	}
	tiny_sort(a, 3);
	while ((*b))
		push_to_a(b, a);

}
