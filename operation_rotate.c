/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/01 21:56:38 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(t_link_list **lst, char *op)
{
	t_link_list	*first;
	t_link_list	*last;

	if (!*lst || !(*lst)->next)
		return ;
	first = *lst;
	last = link_lstlast(*lst);
	*lst = (*lst)->next;
	first->next = NULL;
	last->next = first;
	show_op_msg(op);
}

void	rotate_a(t_link_list **lst)
{
	op_rotate(lst, OP_ROTATE_A);
	update_min_max(*lst);
}

void	rotate_b(t_link_list **lst)
{
	op_rotate(lst, OP_ROTATE_B);
	update_min_max(*lst);
}

void	rotate_both(t_link_list **lsta, t_link_list **lstb)
{
	op_rotate(lsta, NULL);
	update_min_max(*lsta);
	op_rotate(lstb, NULL);
	update_min_max(*lstb);
	show_op_msg(OP_ROTATE_BOTH);
}
