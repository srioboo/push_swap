/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:15:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/29 08:59:50 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_list_size(t_link_list *lst)
{
	int			size; // = 0;
	t_link_list	*tmp = lst;

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
	// int			size;

	if (!*lst)
		*lst = new_list;
	else
	{
		//size = link_lstsize(*lst);
		last = link_lstlast(*lst);
		//last->size = size;
		last->next = new_list;
		// last->next->size = size + 1;
	}
	update_list_size(*lst);

}
