/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/05 10:46:05 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rev_rotate(t_link_list **lst, char *op)
{
	t_link_list	*prev;
	t_link_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	prev = NULL;
	last = *lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
	update_min_max(*lst);
	show_op_msg(op);
}

void	rev_rotate_a(t_link_list **lst)
{
	op_rev_rotate(lst, OP_REV_ROTATE_A); 
}

void	rev_rotate_b(t_link_list **lst)
{
	op_rev_rotate(lst, OP_REV_ROTATE_B);
}

void	ft_rev_rotate_both(t_link_list **lsta, t_link_list **lstb)
{
	op_rev_rotate(lsta, OP_REV_ROTATE_A);
	op_rev_rotate(lstb, OP_REV_ROTATE_B);
	show_op_msg(OP_REV_ROTATE_BOTH);
}
