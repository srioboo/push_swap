/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/08 18:23:24 by srioboo-         ###   ########.fr       */
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
	if (list_size == 3)
		tiny_sort(list_a);
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

void	tiny_sort(t_link_list **list_a)
{
	int	max_val;

	max_val = (*list_a)->max_val;
	if ((*list_a)->content == max_val)
		rotate_a(list_a);
	if ((*list_a)->next->content == max_val)
		rev_rotate_a(list_a);
	if (((*list_a)->content > (*list_a)->next->content))
		swap_a(list_a);
}

void	medium_sort(t_link_list **list_a, t_link_list **list_b)
{
	int	minor;
	int	max;
	t_link_list *aux;

	aux = *list_a;
	minor = (*list_a)->min_val;
	max = (*list_a)->max_val;

	while ((*list_a)->content != minor)
		rotate_a(list_a);
	push_to_b(list_a, list_b);

	aux = *list_a;
	while (aux->next)
	{
		aux->min_val = set_min(minor, aux->content);
		minor = aux->content;
		aux = aux->next;
	}
	(*list_a)->max_val = max;
	(*list_a)->min_val = minor;

	while ((*list_a)->content != minor)
		rotate_a(list_a);
	push_to_b(list_a, list_b);

	log_lst_data(*list_a, "test ps-> list_a");
	log_lst_data(*list_b, "test ps-> list_b");

	tiny_sort(list_a);
	//log_lst_data(*list_a, "test ps tiny -> list_a");

	push_to_a(list_b, list_a);
	rotate_a(list_a);
	push_to_a(list_b, list_a);
	rotate_a(list_a);

	// log_lst_data(*list_a, "test ps push -> list_a");

}
