/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_swap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/07 11:09:52 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_swap(t_list *lst, char *op)
{
	t_list	*aux;
	void	*temp;
	int		i;

	if (!lst || !lst->next)
		return (NULL);
	aux = NULL;
	i = 0;
	while (lst)
	{
		if (lst->content && i == 0)
		{
			temp = lst->content;
			ft_lstadd_back(&aux, ft_lstnew(lst->next->content));
		}
		else if (lst->content && i == 1)
			ft_lstadd_back(&aux, ft_lstnew(temp));
		else
			ft_lstadd_back(&aux, ft_lstnew(lst->content));
		lst = lst->next;
		i++;
	}
	ft_utils_show_op_msg(op);
	return (aux);
}

t_list	*ft_swap_a(t_list *lst)
{
	return (ft_swap(lst, OP_SWAP_A));
}

t_list	*ft_swap_b(t_list *lst)
{
	return (ft_swap(lst, OP_SWAP_B));
}
