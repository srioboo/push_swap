/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/05 09:45:32 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_swap(t_link_list **lst, char *op)
{
	t_link_list	*first;	
	t_link_list	*second;
	int			temp;
	int			i;

	if (!lst || !*lst || !((*lst)->next))
		return ;
	second = NULL;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	show_op_msg(op);
}

void	swap_a(t_link_list **lst)
{
	op_swap(lst, OP_SWAP_A);
}

void	swap_b(t_link_list **lst)
{
	op_swap(lst, OP_SWAP_B);
}
