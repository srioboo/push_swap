/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/22 23:23:53 by srioboo-         ###   ########.fr       */
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

int	is_array_sorted(t_link_list **ls)
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

void	op_sort(t_link_list **list_a, t_link_list **list_b)
{
	int	list_size;

	list_size = link_lstsize(*list_a);
	if (list_size < 4)
		tiny_sort(list_a, list_size);
	else if (list_size == 4 || list_size == 5)
		medium_sort(list_a, list_b);
	else
		full_sort(list_a, list_b);
}

// static void	radix_sort_stack_b(t_link_list **a, t_link_list **b, int b_size, int bit_size, int j)
// {
// 	while (b_size-- && j <= bit_size && !is_array_sorted(a))
// 	{
// 		if ((((*b)->content >> j) & 1) == 0)
// 			rev_rotate_b(b); 
// 		else
// 			push_to_b(b, a);
// 	}
// 	if (is_array_sorted(a))
// 		while (*b)
// 			push_to_b(b, a);
// }

void	full_sort(t_link_list **list_a, t_link_list **list_b)
{
	unsigned int	binary_content;
	int				i;
	int				bit_size;
	int				size;

	bit_size = calculate_max_bits((*list_a)->max_val, (*list_a)->min_val);
	i = -1;
	while (++i < bit_size)
	{
		size = link_lstsize(*list_a);
		while (size--) // && !is_array_sorted(list_a))
		{
			binary_content = (((unsigned int)(*list_a)->content) ^ 0x80000000);
			if (((binary_content >> i) & 1) == 0)
				push_to_b(list_a, list_b);
			else
				rotate_a(list_a);
		}
		while (*list_b)
			push_to_a(list_b, list_a);

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
	int	rep;

	rep = 2;
	while (rep-- > 0)
	{
		if (link_lstlast(*list_a)->content == (*list_a)->min_val)
			rev_rotate_a(list_a);
		while ((*list_a)->content != (*list_a)->min_val)
			rotate_a(list_a);
		push_to_b(list_a, list_b);
	}
	tiny_sort(list_a, 3);
	while ((*list_b))
		push_to_a(list_b, list_a);

}
