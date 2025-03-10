/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:18:16 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 00:37:47 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link_list	*ft_llstnew(int value)
{
	t_link_list	*newlst;

	newlst = (t_link_list *)malloc(sizeof(t_link_list));
	if (!newlst)
		return (NULL);
	newlst->content = value;
	newlst->next = NULL;
	// newlst->index = 0;
	// newlst->index_last = 0;
	// newlst->prev
	return (newlst);
}
