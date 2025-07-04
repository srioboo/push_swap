/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/04 15:47:35 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_list(t_link_list *a)
{
	int			size;
	int			*values;
	t_link_list	*tmp;
	int			i;
	int			j;
	int			temp;

	size = link_lstsize(a);
	values = malloc(sizeof(int) * size);
	if (!values)
		return ;
	// Copia los valores content (no index) a un array
	tmp = a;
	i = 0;
	while (tmp)
	{
		values[i++] = tmp->content;
		tmp = tmp->next;
	}
	// Ordena el array usando bubble sort
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (values[j] > values[j + 1])
			{
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	// Asigna el índice normalizado a cada nodo
	tmp = a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == values[i])
			{
				tmp->index = i;  // Asigna la posición en el array ordenado
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(values);
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
	{
		normalize_list(*a);
		full_sort(a, b);
	}
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
	i = 0;
	while (i < bit_size)
	{
		size = link_lstsize(*a);
		while (size-- > 0)
		{
			if ((((*a)->index >> i) & 1) == 0)
				push_to_b(a, b);
			else
				rotate_a(a);
		}
		while ((*b)->next)
			push_to_a(b, a);
		i++;
	}
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
	while ((*b)->next)
		push_to_a(b, a);
}
