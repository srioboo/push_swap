/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/10 15:05:30 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*op_rotate(t_list *lst, char *op)
{
	int		counter;
	t_list	*last;
	t_list	*aux;

	last = NULL;
	aux = NULL;
	last = ft_lstlast(lst);
	ft_lstadd_back(&aux, last);
	counter = 0;
	while (lst && counter < (ft_lstsize(lst) - 1))
	{
		if (lst->content)
			ft_lstadd_back(&aux, ft_lstnew(lst->content)); 
		counter++;
		lst = lst->next;
	}
	show_op_msg(op);
	return (aux);
}

void	op_rotate_both(t_list *lsta, t_list *lstb)
{
	op_rotate(lsta, OP_ROTATE_A);
	op_rotate(lstb, OP_ROTATE_B);
	show_op_msg(OP_ROTATE_BOTH);
}