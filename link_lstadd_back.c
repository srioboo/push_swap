/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:15:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/27 21:23:44 by srioboo-         ###   ########.fr       */
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
		last->next->index = index + 1;
	}
}
