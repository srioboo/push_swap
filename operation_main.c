/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 22:55:41 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sort(t_list *new_list, t_list *aux_list)
{
	// printf("START SORTENING: list size %d %p", ft_lstsize(new_list), aux_list);
	if (ft_lstsize(new_list) == 3)
		tiny_short(new_list);
	else
		printf("%p", aux_list);

	// printf("START SORTENING: list size %d %p", ft_lstsize(new_list), aux_list);
	// TODO - do ordering
}

void tiny_short(t_list *lst)
{
	int nb_current;
	int nb_next;
	int	max;

	nb_current = 0;
	nb_next = 0;
	max = find_max(lst);
	while (lst)
	{
		if (ft_atoi(lst->content) == max)
			lst = op_rotate(lst, OP_ROTATE_A);
		if (lst->next)
			nb_next = ft_atoi(lst->next->content);
		if (nb_current > nb_next)
			lst = op_swap(lst, OP_SWAP_A);
		lst = lst->next;
	}
}

int	find_max(t_list *lst)
{
	int nb_current;
	int nb_next;
	int max;

	nb_current = 0;
	nb_next = 0;
	max = 0;

	while (lst)
	{
		if (lst->content)
			nb_current = ft_atoi(lst->content);
		if (lst->next)
			nb_next = ft_atoi(lst->next->content);
		if ((nb_current >= nb_next) && (nb_current > max))
			max = nb_current;
		lst = lst->next;
	}
	return (max);
}