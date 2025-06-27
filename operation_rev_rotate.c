/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/27 21:48:13 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rev_rotate(t_link_list **lst, char *op)
{
	int			counter;
	int			last_pos;
	t_link_list	*last;
	t_link_list	*result;

	last_pos = link_lstsize((*lst)) - 1;
	last = NULL;
	result = NULL;
	counter = 0;
	while (*lst)
	{
		// ft_printf("f: %d", (*lst)->content);
		if (counter >= 0 && counter != last_pos)
			link_lstadd_back(&result, link_lstnew((*lst)->content));
		if (counter == last_pos)
			last = link_lstnew((*lst)->content);
		//else
		//	ft_printf("f: %d", (*lst)->content);
		counter++;
		(*lst) = (*lst)->next;
	}
	link_lstadd_front(&result, last);
	*lst = result;
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
