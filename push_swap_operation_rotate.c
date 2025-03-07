/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/07 13:00:15 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_rotate(t_list *lst, char *op)
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
	ft_utils_show_op_msg(op);
	return (aux);
}
