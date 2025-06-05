/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/05 12:08:30 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(t_link_list **lst, char *op)
{
	int			counter;
	int			last_pos;
	t_link_list	*last;
	t_link_list	*aux;

	last_pos = link_lstsize((*lst)) - 1;
	last = NULL;
	aux = NULL;
	counter = 0;
	while (*lst && (counter <= last_pos))
	{
		if ((*lst)->content && (counter == 0))
			last = link_lstnew((*lst)->content);
		else if ((*lst)->content && (counter > 0))
			link_lstadd_back(&aux, link_lstnew((*lst)->content));
		counter++;
		(*lst) = (*lst)->next;
	}
	link_lstadd_back(&aux, last);
	*lst = aux;
	show_op_msg(op);
}

void	rotate_a(t_link_list **lst)
{
	op_rotate(lst, OP_ROTATE_A);
}

void	rotate_b(t_link_list **lst)
{
	op_rotate(lst, OP_ROTATE_B);
}

void	rotate_both(t_link_list **lsta, t_link_list **lstb)
{
	op_rotate(lsta, NULL);
	op_rotate(lstb, NULL);
	show_op_msg(OP_ROTATE_BOTH);
}
