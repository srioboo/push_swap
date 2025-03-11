/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:17:59 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 23:16:45 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link_list	*ft_lstmap(t_link_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_link_list	*new;
	t_link_list	*aux;

	new = NULL;
	while (lst)
	{
		aux = ft_lstnew(0);
		if (!aux)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		aux->content = f(lst->content);
		ft_lstadd_back(&new, aux);
		lst = lst->next;
	}
	return (new);
}
