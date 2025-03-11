/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:17:59 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/10 09:18:11 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;

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
