/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:15:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/29 12:45:25 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_list_size(t_link_list *lst)
{
	int			size;
	t_link_list	*tmp;

	size = 0;
	tmp = lst;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp)
	{
		tmp->size = size;
		tmp = tmp->next;
	}
}

void	link_lstadd_back(t_link_list **lst, t_link_list *new_list)
{
	t_link_list	*last;

	if (!*lst)
		*lst = new_list;
	else
	{
		last = link_lstlast(*lst);
		last->next = new_list;
	}
	update_list_size(*lst);
}
