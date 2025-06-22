/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/22 17:18:30 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	calculate_max_bits(int max_val)
// {
// 	int	max_bits;

// 	max_bits = 0;
// 	while ((max_val >> max_bits) != 0)
// 		max_bits++;
// 	return (max_bits);
// }

int	is_array_sorted(t_link_list **lst)
{
	int	i;

	i = 0;
	while (i < (link_lstsize(*lst) - 1))
	{
		if (((*lst)->content) > ((*lst)->next->content))
			return (0);
		i++;
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

void	full_sort(t_link_list **list_a, t_link_list **list_b)
{
	unsigned int	binary_content;
	int				i;
	int				bit_size;
	int				size;

	bit_size = 0;
	size = link_lstsize(*list_a);
	while (size > 1 && ++bit_size)
		size /= 2;
	// bit_size = calculate_bit_size((*list_a)->max_val);
	i = -1;
	while (++i <= bit_size)
	{
		size = link_lstsize(*list_a);
		while (size--) // && !is_array_sorted(list_a))
		{
			// binary_content = (*list_a)->content;
			binary_content = (((unsigned int)(*list_a)->content) ^ 0x80000000);
			if (((binary_content >> i) & 1) == 0)
				push_to_b(list_a, list_b);
			else
				rotate_a(list_a);
		}
		// if (is_array_sorted(list_b))
		// TODO order b
	}
	while (*list_b)
		push_to_a(list_b, list_a);
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

// void	sort_four_to_five_elements(t_stacks *s)
// {
// 	while (s->b_size <= 1)
// 	{
// 		if (s->a[0] == 0 || s->a[0] == 1)
// 			push("pb", s);
// 		else
// 			rotate(s->a, s->a_size, "up", "a");
// 	}
// 	if (s->b[0] == 0)
// 		swap("sb", s->b, s->b_size);
// 	if (s->a[2] != 4)
// 	{
// 		if (s->a[0] == 4)
// 			rotate(s->a, s->a_size, "up", "a");
// 		else
// 			rotate(s->a, s->a_size, "down", "a");
// 	}
// 	if (s->a[0] > s->a[1])
// 		swap("sa", s->a, s->a_size);
// 	push("pa", s);
// 	push("pa", s);
// }

