/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 23:32:05 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link_list	*op_swap(t_link_list *lst, char *op)
{
	t_link_list	*aux;
	int			temp;
	int			i;

	if (!lst || !lst->next)
		return (NULL);
	aux = NULL;
	i = 0;
	while (lst)
	{
		if (lst->content && i == 0)
		{
			temp = lst->content;
			link_lstadd_back(&aux, link_lstnew(lst->next->content));
		}
		else if (lst->content && i == 1)
			link_lstadd_back(&aux, link_lstnew(temp));
		else
			link_lstadd_back(&aux, link_lstnew(lst->content));
		lst = lst->next;
		i++;
	}
	show_op_msg(op);
	return (aux);
}
