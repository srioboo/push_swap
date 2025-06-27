/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/27 21:30:33 by srioboo-         ###   ########.fr       */
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
		//ft_printf("t");
		if ((counter == 0))
			last = link_lstnew((*lst)->content);
		else if ((counter > 0))
			link_lstadd_back(&aux, link_lstnew((*lst)->content));
		counter++;
		(*lst) = (*lst)->next;
	}
	link_lstadd_back(&aux, last);
	//ft_printf("t");
	*lst = aux;
	//ft_printf("t");
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
