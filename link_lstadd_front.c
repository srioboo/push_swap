/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:14:31 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/26 14:53:19 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	link_lstadd_front(t_link_list **lst, t_link_list *new)
{
	new->next = *lst;
	*lst = new;
	// TODO - REINDEX
}
