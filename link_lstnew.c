/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:18:16 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/19 10:28:23 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link_list	*link_lstnew(int value)
{
	t_link_list	*newlst;

	newlst = (t_link_list *)malloc(sizeof(t_link_list));
	if (!newlst)
		return (NULL);
	newlst->content = value;
	newlst->next = NULL;
	newlst->index = 0;
	return (newlst);
}
