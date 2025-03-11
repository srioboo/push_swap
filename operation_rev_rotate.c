/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 23:28:04 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link_list *op_rev_rotate(t_link_list *lst, char *op)
{
	int		counter;
	t_link_list	*first;
	t_link_list	*aux;

	first = NULL;
	aux = NULL;
	counter = 0;
	while (lst)
	{
		if (lst->content && counter == 0)
			first = link_lstnew(lst->content);
		else if (lst->content)
			link_lstadd_back(&aux, link_lstnew(lst->content));
		counter++;
		lst = lst->next;
	}
	link_lstadd_back(&aux, first);
	show_op_msg(op);
	return (aux);
}

void	ft_rev_rotate_both(t_link_list *lsta, t_link_list *lstb)
{
	op_rev_rotate(lsta, OP_REV_ROTATE_A);
	op_rev_rotate(lstb, OP_REV_ROTATE_B);
	show_op_msg(OP_REV_ROTATE_BOTH);
}
