/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_rev_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/07 21:51:36 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_rev_rotate(t_list *lst, char *op)
{
	int		counter;
	t_list	*first;
	t_list	*aux;

	first = NULL;
	aux = NULL;
	counter = 0;
	while (lst)
	{
		if (lst->content && counter == 0)
			first = ft_lstnew(lst->content);
		else if (lst->content)
			ft_lstadd_back(&aux, ft_lstnew(lst->content));
		counter++;
		lst = lst->next;
	}
	ft_lstadd_back(&aux, first);
	ft_utils_show_op_msg(op);
	return (aux);
}

void	ft_rev_rotate_both(t_list *lsta, t_list *lstb)
{
	ft_rev_rotate(lsta, OP_REV_ROTATE_A);
	ft_rev_rotate(lstb, OP_REV_ROTATE_B);
	ft_utils_show_op_msg(OP_REV_ROTATE_BOTH);
}
