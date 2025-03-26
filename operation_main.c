/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/28 00:03:27 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link_list	*op_sort(t_link_list *new_list, t_link_list *aux_list)
{
	// ft_printf("START SORTENING: list size %d %p", ft_lstsize(new_list), aux_list);
	if (link_lstsize(new_list) == 3)
		aux_list = tiny_sort(new_list, aux_list);
	else
		aux_list = full_sort(new_list, aux_list);// printf("%p", aux_list);

	// ft_printf("START SORTENING: list size %d %p", ft_lstsize(new_list), aux_list);
	// TODO - do ordering
	return (aux_list);
}

t_link_list	*full_sort(t_link_list *lst, t_link_list *aux)
{
	int	count;
	int	max;

	// TODO - redo implementation
	max = find_max(lst);
	count = 0;
	while (lst)
	{
		op_push(&lst, aux, OP_PUSH_B);
		// if (count == 0 && (lst->content == max))
		// 	aux = op_rotate(lst, OP_ROTATE_A);
		// else if (count == 0 && (lst->content != max))
		// {
		// 	aux = op_swap(lst, OP_SWAP_A);
		// 	aux = op_rotate(aux, OP_ROTATE_A);
		// }
		lst = lst->next;
		count++;
	}
	return (aux);
}

t_link_list	*tiny_sort(t_link_list *lst, t_link_list *aux)
{
	int	count;
	int	max;

	max = find_max(lst);
	count = 0;
	while (lst)
	{
		if (count == 0 && (lst->content == max))
			op_rotate(&lst, OP_ROTATE_A);
		else if (count == 0 && (lst->content != max))
		{
			aux = op_swap(lst, OP_SWAP_A);
			op_rotate(&aux, OP_ROTATE_A);
		}
		lst = lst->next;
		count++;
	}
	return (aux);
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