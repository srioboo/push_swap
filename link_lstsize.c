/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:18:33 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 09:53:00 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	link_lstsize(t_link_list *lst)
{
	int	lstsize;

	lstsize = 1;
	if (lst == NULL)
		return (0);
	while (lst->next)
	{
		lstsize++;
		lst = lst->next;
	}
	return (lstsize);
}
