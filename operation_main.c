/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 09:09:52 by srioboo-         ###   ########.fr       */
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

	nb_current = 0;
	nb_next = 0;
	while (lst)
	{
		if (lst->content)
			nb_current = ft_atoi(lst->content);
		if (lst->next)
			nb_next = ft_atoi(lst->next->content);

		if (nb_current > nb_next)
		{
			lst = op_rotate(lst, OP_ROTATE_A);
		}
		lst = lst->next;
	}
}