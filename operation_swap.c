/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/10 15:01:14 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*op_swap(t_list *lst, char *op)
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
	show_op_msg(op);
	return (aux);
}
