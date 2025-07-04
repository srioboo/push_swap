/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/04 19:25:16 by srioboo-         ###   ########.fr       */
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
