/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:15:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/08 16:42:27 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	link_lstadd_back(t_link_list **lst, t_link_list *new_list)
{
	t_link_list	*last;
	int			index;

	if (!*lst)
		*lst = new_list;
	else
	{
		index = link_lstsize(*lst);
		last = link_lstlast(*lst);
		last->index = index;
		last->prev = *lst;
		last->next = new_list;
		(*lst)->max_val = set_max(new_list->max_val, (*lst)->max_val);
		(*lst)->min_val = set_min(new_list->min_val, (*lst)->min_val);
		last->next->index = index + 1;
	}
}
