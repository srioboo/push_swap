/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 23:32:49 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link_list	*op_rotate(t_link_list *lst, char *op)
{
	int		counter;
	t_link_list	*last;
	t_link_list	*aux;

	last = NULL;
	aux = NULL;
	last = link_lstlast(lst);
	link_lstadd_back(&aux, last);
	counter = 0;
	while (lst && counter < (link_lstsize(lst) - 1))
	{
		if (lst->content)
			link_lstadd_back(&aux, link_lstnew(lst->content)); 
		counter++;
		lst = lst->next;
	}
	show_op_msg(op);
	return (aux);
}

void	op_rotate_both(t_link_list *lsta, t_link_list *lstb)
{
	op_rotate(lsta, OP_ROTATE_A);
	op_rotate(lstb, OP_ROTATE_B);
	show_op_msg(OP_ROTATE_BOTH);
}