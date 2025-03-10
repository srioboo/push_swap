/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 00:39:08 by srioboo-         ###   ########.fr       */
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
	while (lst)
	{
		if ((lst->content > lst->next->content) 
			&& (lst->content > lst->next->next->content))
		{
			lst = op_rotate(lst, OP_ROTATE_A);
		}
	}
}