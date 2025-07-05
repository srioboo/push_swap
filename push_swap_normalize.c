/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/05 09:51:10 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_values_to_array(t_link_list *a, int *values)
{
	t_link_list	*tmp;
	int			i;

	tmp = a;
	i = 0;
	while (tmp)
	{
		values[i++] = tmp->content;
		tmp = tmp->next;
	}
}

static void	bubble_sort_array(int *values, int size)
{
	int	i;
	int	j;
	int	temp;

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
}

static void	assign_normalized_indexes(t_link_list *a, int *values, int size)
{
	t_link_list	*tmp;
	int			i;

	tmp = a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == values[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	normalize_list(t_link_list *a)
{
	int	size;
	int	*values;

	size = link_lstsize(a);
	values = malloc(sizeof(int) * size);
	if (!values)
		return ;
	copy_values_to_array(a, values);
	bubble_sort_array(values, size);
	assign_normalized_indexes(a, values, size);
	free(values);
}
